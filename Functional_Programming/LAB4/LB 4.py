from functools import partial, reduce
from itertools import islice

# 1) Каррированная функция фильтрации по полю
filter_by = lambda key: lambda value: lambda items: tuple(
    item for item in items if item.get(key) == value
)

# Плоская (некаррированная) версия — для демонстрации partial
filter_by_flat = lambda key, value, items: tuple(
    item for item in items if item.get(key) == value
)

# Каррированный предикат сравнения
greater_than = lambda threshold: lambda x: x > threshold


TOOL = [
    {"name": "hammer",      "category": "tools"},
    {"name": "pliers",      "category": "tools"},
    {"name": "screwdriver", "category": "tools"},
    {"name": "apple",       "category": "fruit"},
    {"name": "banana",      "category": "fruit"},
]

NUMBERS = [12, 6123, 8, 2, 1, 42, 77, 3]


if __name__ == "__main__":
    # 2) Ручное каррирование
    print("=== каррирование: filter_by('category')('tools')(TOOL) ===")
    print(filter_by("category")("tools")(TOOL))

    # 3) partial на плоской функции — фиксируем аргументы по одному
    print("\n=== partial: сначала key, потом value ===")
    by_category = partial(filter_by_flat, "category")
    print(by_category("tools")(TOOL))

    print("\n=== двойной partial сразу двумя аргументами ===")
    print(partial(filter_by_flat, "category", "fruit")(TOOL))

    # 4) Каррированный предикат + filter
    print("\n=== greater_than(5) через filter ===")
    print(tuple(filter(greater_than(5), NUMBERS)))

    print("\n=== greater_than(100) через filter ===")
    print(tuple(filter(greater_than(100), NUMBERS)))

    # 5) Ленивый конвейер: filter -> map -> islice
    print("\n=== первые 3 значения > 5, умноженные на 10 ===")
    print(tuple(islice(
        map(lambda x: x * 10, filter(greater_than(5), NUMBERS)),
        3,
    )))

    # 6) reduce поверх ленивого потока
    print("\n=== сумма первых 3 чисел > 5 ===")
    print(reduce(
        lambda acc, x: acc + x,
        islice(filter(greater_than(5), NUMBERS), 3),
        0,
    ))

    print("\n=== имена первых 3 инструментов через ' | ' ===")
    print(reduce(
        lambda acc, it: acc + (" | " if acc else "") + it["name"],
        islice(filter_by("category")("tools")(TOOL), 3),
        "",
    ))
