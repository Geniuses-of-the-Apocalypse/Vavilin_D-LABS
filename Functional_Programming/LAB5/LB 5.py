from functools import reduce

STUDENTS = tuple((
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5}
))

# ===( 1 )===
FORMATTED_STUDENTS = map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", STUDENTS)

# ===( 2 )===
FILTERED_STUDENTS = filter(lambda s: s['grade'] > 4.0, STUDENTS)

print(tuple(FORMATTED_STUDENTS))
print(tuple(FILTERED_STUDENTS))

# ===( 3 )===
TOTAL_AGE, COUNT = reduce(
    lambda acc, student: (acc[0] + student["age"], acc[1] + 1),filter(lambda s: s['grade'] > 4.0, STUDENTS),(0, 0),)

print(TOTAL_AGE / COUNT)
