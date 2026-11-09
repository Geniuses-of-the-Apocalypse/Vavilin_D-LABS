from functools import partial

# ===( 1 )===
filter_by = lambda key: lambda value: lambda items: [
    item for item in items if item.get(key) == value
]


# ===( 2 )===
# Вариант А: применяем каррированную filter_by к key.
filter_by_category = filter_by("category")

# Вариант Б: partial на некаррированной функции.
filter_by_raw = lambda key, value, items: [
    item for item in items if item.get(key) == value
]
filter_by_category_p = partial(filter_by_raw, "category")
filter_fruits_p      = partial(filter_by_category_p, "fruit")
https://github.com/Geniuses-of-the-Apocalypse/Vavilin_D-LABS/blob/main/Functional_Programming/LAB4/LB%204.py

# ===( 3 )===
greater_than = lambda threshold: lambda x: x > threshold

over_five  = greater_than(5)
over_ten   = greater_than(10)

# === MAIN ===
if __name__ == "__main__":
    items = [
        {"name": "apple",  "category": "fruit"},
        {"name": "carrot", "category": "vegetable"},
        {"name": "banana", "category": "fruit"},
    ]

    print("УРОВЕНЬ 1: Ручное каррирование")
    fruits = filter_by("category")("fruit")(items)
    print("filter_by('category')('fruit')(items):")
    print("  ", fruits)

    print()
    print("УРОВЕНЬ 2: Functools.partial")
    filter_fruits = filter_by_category("fruit")
    print("filter_by('category')('fruit')(items):")
    print("  ", filter_fruits(items))

    print("\nДвойной partial на некаррированной функции:")
    print("  ", filter_fruits_p(items))

    print()
    print("УРОВЕНЬ 3: Greater_than + filter")
    numbers = [1, 6, 8, 2, 9, 12, 3]
    print("numbers:        ", numbers)
    print("over_five:      ", list(filter(over_five, numbers)))
    print("over_ten:       ", list(filter(over_ten, numbers)))

    # Комбинация с map: удвоить только те, что > 5
    print("x*2 для x > 5:  ", list(map(lambda x: x * 2, filter(over_five, numbers))))
