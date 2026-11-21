// === ЭЛЕМЕНТЫ ===
const form = document.getElementById("task-form");
const formTitle = document.getElementById("form-title");
const taskIdInput = document.getElementById("task-id");
const titleInput = document.getElementById("title");
const dueAtInput = document.getElementById("due_at");
const descriptionInput = document.getElementById("description");
const titleCounter = document.getElementById("title-counter");
const formError = document.getElementById("form-error");
const submitBtn = document.getElementById("submit-btn");
const cancelBtn = document.getElementById("cancel-btn");
const tasksList = document.getElementById("tasks-list");
const emptyState = document.getElementById("empty-state");

// === УТИЛИТЫ ===

function formatDate(iso) {
    const d = new Date(iso);
    if (isNaN(d)) return iso;
    const pad = (n) => String(n).padStart(2, "0");
    return `${pad(d.getDate())}.${pad(d.getMonth() + 1)}.${d.getFullYear()} ${pad(d.getHours())}:${pad(d.getMinutes())}`;
}

function escapeHtml(str) {
    return String(str)
        .replaceAll("&", "&amp;")
        .replaceAll("<", "&lt;")
        .replaceAll(">", "&gt;")
        .replaceAll('"', "&quot;")
        .replaceAll("'", "&#039;");
}

function showError(message) {
    formError.textContent = message;
    formError.hidden = false;
}

function hideError() {
    formError.hidden = true;
    formError.textContent = "";
}

function resetForm() {
    form.reset();
    taskIdInput.value = "";
    formTitle.textContent = "Новая задача";
    submitBtn.textContent = "Создать";
    cancelBtn.hidden = true;
    titleCounter.textContent = "0";
    hideError();
}

function enterEditMode(task) {
    taskIdInput.value = task.id;
    titleInput.value = task.title;
    descriptionInput.value = task.description || "";
    dueAtInput.value = task.due_at.slice(0, 16);
    titleCounter.textContent = titleInput.value.length;
    formTitle.textContent = "Редактировать задачу";
    submitBtn.textContent = "Сохранить";
    cancelBtn.hidden = false;
    hideError();
    form.scrollIntoView({ behavior: "smooth", block: "start" });
    titleInput.focus();
}

// === СЧЁТЧИК СИМВОЛОВ ===
titleInput.addEventListener("input", () => {
    titleCounter.textContent = titleInput.value.length;
});

// === ЗАГРУЗКА И РЕНДЕР СПИСКА ===
async function loadTasks() {
    try {
        const res = await fetch("/api/tasks");
        if (!res.ok) throw new Error("Не удалось загрузить задачи");
        const tasks = await res.json();
        renderTasks(tasks);
    } catch (e) {
        tasksList.innerHTML = `<p class="empty-state">Ошибка: ${escapeHtml(e.message)}</p>`;
    }
}

function renderTasks(tasks) {
    tasksList.innerHTML = "";

    if (tasks.length === 0) {
        tasksList.appendChild(emptyState);
        emptyState.hidden = false;
        return;
    }
    emptyState.hidden = true;

    for (const task of tasks) {
        const card = document.createElement("div");
        card.className = "task" + (task.is_overdue ? " overdue" : "");
        card.dataset.id = task.id;

        const descriptionHtml = task.description
            ? `<div class="task-description">${escapeHtml(task.description)}</div>`
            : `<div class="task-description empty">Без описания</div>`;

        const overdueBadge = task.is_overdue
            ? `<span class="overdue-badge">просрочено</span>`
            : "";

        card.innerHTML = `
            <div class="task-header">
                <div class="task-date">
                    ${formatDate(task.due_at)}
                    ${overdueBadge}
                </div>
                <div class="task-title" title="${escapeHtml(task.title)}">
                    ${escapeHtml(task.title)}
                </div>
            </div>
            <div class="task-body">
                ${descriptionHtml}
                <div class="task-actions">
                    <button type="button" class="btn btn-small btn-edit">Редактировать</button>
                    <button type="button" class="btn btn-small btn-delete">Удалить</button>
                </div>
            </div>
        `;

        card.querySelector(".task-header").addEventListener("click", () => {
            card.classList.toggle("open");
        });

        card.querySelector(".btn-edit").addEventListener("click", (e) => {
            e.stopPropagation(); 
            enterEditMode(task);
        });

        card.querySelector(".btn-delete").addEventListener("click", async (e) => {
            e.stopPropagation();
            if (!confirm(`Удалить задачу «${task.title}»?`)) return;
            await deleteTask(task.id);
        });

        tasksList.appendChild(card);
    }
}

// === СОЗДАНИЕ И ОБНОВЛЕНИЕ

form.addEventListener("submit", async (e) => {
    e.preventDefault();
    hideError();

    const payload = {
        title: titleInput.value.trim(),
        description: descriptionInput.value.trim(),
        due_at: dueAtInput.value,
    };

    if (!payload.title) return showError("Название не может быть пустым");
    if (payload.title.length > 100) return showError("Название не должно превышать 100 символов");
    if (!payload.due_at) return showError("Укажите дату и время");

    const id = taskIdInput.value;
    const url = id ? `/api/tasks/${id}` : "/api/tasks";
    const method = id ? "PUT" : "POST";

    try {
        const res = await fetch(url, {
            method,
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify(payload),
        });

        if (!res.ok) {
            const data = await res.json().catch(() => ({}));
            throw new Error(data.error || "Ошибка сохранения");
        }

        resetForm();
        await loadTasks();
    } catch (err) {
        showError(err.message);
    }
});

// === УДАЛЕНИЕ ===

async function deleteTask(id) {
    try {
        const res = await fetch(`/api/tasks/${id}`, { method: "DELETE" });
        if (!res.ok) {
            const data = await res.json().catch(() => ({}));
            throw new Error(data.error || "Ошибка удаления");
        }
        if (taskIdInput.value === String(id)) resetForm();
        await loadTasks();
    } catch (err) {
        showError(err.message);
    }
}

// === ОТМЕНА РЕДАКТИРОВАНИЯ ===
cancelBtn.addEventListener("click", resetForm);

// === ЗАПУСК ===
loadTasks();