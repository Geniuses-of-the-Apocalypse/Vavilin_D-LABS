# 34e41be78af755cd91d9b9a82a943e5a2ccd1db0bdf2ccb64db28902ea326157

from functools import reduce

STUDENTS = tuple((
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5}
))

# ===( 1 )===
def formatted():
    def run(students):
        return map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", students)
    return run

# ===( 2 )===
def filtered():
    def run(students):
        return filter(lambda s: s['grade'] > 4.0, students)
    return run

# ===( 3 )===
def total_age_and_count():
    def run(students):
        return reduce(
            lambda acc, student: (acc[0] + student["age"], acc[1] + 1),
            filter(lambda s: s['grade'] > 4.0, students),
            (0, 0),
        )
    return run

fmt  = formatted()          
flt  = filtered()          
tot  = total_age_and_count()  

print(tuple(fmt(STUDENTS)))
print(tuple(flt(STUDENTS)))

TOTAL_AGE, COUNT = tot(STUDENTS)
print(TOTAL_AGE / COUNT)
