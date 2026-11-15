from datetime import datetime
from flask import Flask, jsonify, request, render_template

import db

app = Flask(__name__)

TITLE_MAX_LEN = 100

# === УТИЛИТЫ ===

def parse_due_at(raw):
    if not raw or not isinstance(raw, str):
        raise ValueError("Дата и время обядательны")
    try:
        dt = datetime.fromisoformat(raw)
    except ValueError:
        raise ValueError("Неверный формат даты и времени")
    dt = dt.replace(second=0, microsecond=0)
    return dt.strftime("%Y-%m-%dT%H:%M:00")

def validate_payload(data, task_id=None):
    if not isinstance(data, dict):
        raise ValueError("Ожидается JSON-объект")

    title = (data.get("title") or "").strip()
    if not title:
        raise ValueError("Название не может быть пустым")
    if len(title) > TITLE_MAX_LEN:
        raise ValueError(f"Название не должно превышать {TITLE_MAX_LEN} символов")

    description = (data.get("description") or "").strip()

    due_at_raw = data.get("due_at")
    due_at_norm = parse_due_at(due_at_raw)

    due_dt = datetime.fromisoformat(due_at_norm)
    if due_dt < datetime.now():
        raise ValueError("Дата и время не могут быть в прошлом")

    existing = db.find_task_by_due_at(due_at_norm, exclude_id=task_id)
    if existing:
        raise ValueError("На это время уже есть задача")

    return title, description, due_at_norm

def error(message, status=400):
    return jsonify({"error": message}), status

# === СТРАНИЦА ===

@app.get("/")
def index():
    return render_template("index.html")

# === API ===

@app.get("/api/tasks")
def api_list_task():
    data = request.get_json(silent=True)
    try:
        title, description, due_at = validate_payload(data)
    except ValueError as e:
        return error(str(e))
    task = db.create_task(title, description, due_at)
    return jsonify(task), 201

@app.put("/api/tasks/<int:task_id>")
def api_update_task(task_id):
    if db.get_task(task_id) is None:
        return error("Задача не найдена", 404)
    data = request.get_json(silent=True)
    try:
        title, description, due_at = validate_payload(data, task_id=task_id)
    except ValueError as e:
        return error(str(e))
    task = db.update_task(task_id, title, description, due_at)
    return jsonify(task)

@app.delete("/api/tasks/<int:task_id>")
def api_delete_task(task_id):
    if not db.delete_task(task_id):
        return error ("Задача не найдена", 404)
    return "", 204

# === ЗАПУСК ===
if __name__ == "__main__":
    db.init_db()
    app.run(debug=False, port=5000)