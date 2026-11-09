from functools import partial, reduce

# === ( 1 ) ===
# Возвращаем генератор, а не список
filter_by = lambda key: lambda value: lambda items: (
    item for item in items if item.get(key) == value
)

# === ( 2 ) ===
filter_by_raw = lambda key, value, items: (
    item for item in items if item.get(key) == value
)

# === ( 3 ) ===
greater_than = lambda threshold: lambda x: x > threshold

# === MAIN ===
if __name__ == "__main__":
    items = (
        {"name": "apple",  "category": "fruit"},
        {"name": "carrot", "category": "vegetable"},
        {"name": "banana", "category": "fruit"},
    )

    print("УРОВЕНЬ 1: Ручное каррирование")
    # Генератор → материализуем только в момент печати через tuple
    print("filter_by('category')('fruit')(items):")
    print("  ", tuple(filter_by("category")("fruit")(items)))

    print()
    print("УРОВЕНЬ 2: Functools.partial")
    print("filter_by('category')('fruit')(items):")
    print("  ", tuple(partial(filter_by, "category")("fruit")(items)))

    print("\nДвойной partial на некаррированной функции:")
    print("  ", tuple(
        partial(partial(filter_by_raw, "category"), "fruit")(items)
    ))

    print()
    print("УРОВЕНЬ 3: greater_than + filter + reduce")
    numbers = (1, 6, 8, 2, 9, 12, 3)
    print("numbers:        ", numbers)
    print("over_five:      ", tuple(filter(greater_than(5), numbers)))
    print("over_ten:       ", tuple(filter(greater_than(10), numbers)))

    print("x*2 для x > 5:  ", tuple(
        map(lambda x: x * 2, filter(greater_than(5), numbers))
    ))

    print("reduce: сумма x>5: ", reduce(
        lambda acc, x: acc + x,
        filter(greater_than(5), numbers),
        0,
    ))

    print("reduce: фрукты через запятую: ", reduce(
        lambda acc, it: acc + ("," if acc else "") + it["name"],
        filter_by("category")("fruit")(items),
        "",
    ))
