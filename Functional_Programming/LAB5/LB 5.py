34e41be78af755cd91d9b9a82a943e5a2ccd1db0bdf2ccb64db28902ea326157

from functools import reduce

STUDENTS = tuple((
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5}
))

# ===( 1 )===
def make_formatted:
    def inner(students):
        return map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", students)
    return inner

# ===( 2 )===
def make_filtered:
    def inner(students):
        return filter(lambda s: s['grade'] > 4.0, students)
    return inner

# ===( 3 )===
def make_total_age_and_count:
    def inner(students):
        return reduce(
            lambda acc, student: (acc[0] + student["age"], acc[1] + 1),
            filter(lambda s: s['grade'] > 4.0, students),(0, 0),)
    return inner

# ВЫВОД
print(tuple(make_formatted(STUDENTS)))    
print(tuple(make_filtered(STUDENTS)))    
print(make_total_age_and_count(STUDENTS))
