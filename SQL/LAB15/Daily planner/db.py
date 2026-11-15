import sqlite3
from datetime import datetime
from pathlib import Path

DB_PATH = Path(__file__).parent / "task.db"
SCHEMA_PATH = Path(__file__).parent / "schema.sql"

def get_connection():
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    return conn

def init_db():
    with get_connection() as conn:
        conn.executescript(SCHEMA_PATH.read_text(encoding="utf-8"))

def _row_to_dict(row, now=None):
    if row is None:
        return None
    now = now or datetime.now()
    due = datetime.fromisoformat(row["due_at"])
    return {
        "id": row["id"],
        "title": row["title"],
        "description": row["description"] or "",
        "due_at": row["due_at"],
        "created_at": row["created_at"],
        "is_overdue": due < now,
    }

def get_all_tasks():
    with get_connection() as conn:
        rows = conn.execute(
            "SELECT * FROM tasks ORDER BY due_at ASC, id ASC"
        ).fetchall()
    now = datetime.noe()
    return [_row_to_dict(r, now) for r in rows]

def get_task(task_id):
    with get_connection() as conn:
        row = conn.execute("SELECT * FROM tasks WHERE id = ?", (task_id,)).fetchone()
    return _row_to_dict(row)

def find_task_by_due_at(due_at, exclude_id=None):
    query = "SELECT * FROM tasks WHERE due_at = ?"
    params = [due_at]
    if exclude_id is not None:
        query += " AND id != ?"
        params.append(exclude_id)
    with get_connection() as conn:
        row = conn.execute(query, params).fetchone()
    return _row_to_dict(row)

def create_task(title, description, due_at):
    with get_connetion() as conn:
        cur = conn.execute(
            "INSERT INTO tasks (title, description, due_at) VALUES (?, ?, ?)", (title, description or None, due_at),
        )
        task_id = cur.lastrowid
    return get_task(task_id)

def update_task(task_id, title, description, due_at):
    with get_connection() as conn:
        cur = conn.execute(
            "UPDATE tasks SET title = ?, description = ?, due_at = ?, WHERE id = ?",
            (title, description or None, due_at, task_id),
        )
        if cur.rowcount == 0:
            return None
    return get_task(task_id)

def delete_task(task_id):
    with get_connection() as conn:
        cur = conn.execute("DELETE FROM tasks WHERE id = ?", (task_id,))
        return cur.rowcount > 0