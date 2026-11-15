from db import init_db, create_task, get_all_tasks, update_task, delete_task

init_db()
print("БД инициализирована")

t = create_task("Тестовая задача", "Описание", "2026-12-01T10:00")
print("Создан: ", t)

print("Все задачи: ", get_all_tasks())

update_task(t["id"], "Обновлённая", "Новое описание", "2026-12-02T11:00")
print("После обновления: ", get_all_tasks())

delete_task(t["id"])
print("После удаления: ", get_all_tasks())