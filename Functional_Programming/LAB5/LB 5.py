from functools import reduce

students = [
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5},
]


# ===( 1 )===
def format_students(students):
    return list(map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", students))


# ===( 2 )===
def filter_by_grade(students, threshold=4.0):
    return list(filter(lambda s: s["grade"] > threshold, students))


# ===( 3 )===
def average_age(students):
    if not students:
        return 0.0 

    total = reduce(lambda acc, s: acc + s["age"], students, 0)
    return total / len(students)


if __name__ == "__main__":
    result = top_students_report(students)

    print("Все студенты:")
    for line in result["formatted"]:
        print(" ", line)

    print("\nОценка > 4.0:")
    for s in result["top_students"]:
        print(f"  {s['name']} — {s['grade']}")

    print(f"\nСредний возраст отобранных: {result['avg_age_top']:.2f}")
