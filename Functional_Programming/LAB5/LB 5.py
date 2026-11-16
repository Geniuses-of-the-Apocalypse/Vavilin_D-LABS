from functools import reduce

# === КОНСТАНТЫ ===
STUDENTS = (
    {"name": "Анна",    "age": 20, "grade": 4.5},
    {"name": "Борис",   "age": 22, "grade": 3.8},
    {"name": "Виктор",  "age": 19, "grade": 4.2},
    {"name": "Галина",  "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5},
)

GRADE_THRESHOLD = 4.0

# === ЧИСТЫЕ ФУНКЦИИ ===

# Уровень 1: map — форматирование
def format_students(students):
    return tuple(map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", students))


# Уровень 2: filter — отбор по оценке
def filter_by_grade(students, threshold=GRADE_THRESHOLD):
    return tuple(filter(lambda s: s["grade"] > threshold, students))


# Уровень 3: reduce — средний возраст (одним проходом, без len())
def average_age(students):
    total_age, count = reduce(
        lambda acc, s: (acc[0] + s["age"], acc[1] + 1),
        students,
        (0, 0),
    )
    return total_age / count if count else 0.0


# === РЕЗУЛЬТАТЫ (константы, посчитанные чистыми функциями) ===
FORMATTED_STUDENTS = format_students(STUDENTS)
TOP_STUDENTS = filter_by_grade(STUDENTS, GRADE_THRESHOLD)
AVG_AGE_TOP = average_age(TOP_STUDENTS)


if __name__ == "__main__":
    print("Все студенты:")
    for line in FORMATTED_STUDENTS:
        print(" ", line)

    print("\nОценка > 4.0:")
    for s in TOP_STUDENTS:
        print(f"  {s['name']} — {s['grade']}")

    print(f"\nСредний возраст отобранных: {AVG_AGE_TOP:.2f}")
