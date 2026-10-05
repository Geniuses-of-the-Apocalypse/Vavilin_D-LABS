from functools import partial

# ===( 1 )===
filter_by = lambda key: lambda value: lambda items: [
    item for item in items if item.get(key) == value
]


# ===( 2 )===
# Вариант А: применяем каррированную filter_by к key → получаем lambda value: ...
filter_by_category = filter_by("category")

# Вариант Б: partial на некаррированной функции (фиксируем первые аргументы)
filter_by_raw = lambda key, value, items: [
    item for item in items if item.get(key) == value
]
filter_by_category_p = partial(filter_by_raw, "category")
filter_fruits_p      = partial(filter_by_category_p, "fruit")


# ===( 3 )===
greater_than = lambda threshold: lambda x: x > threshold

# Переиспользуемые предикаты
over_five  = greater_than(5)
over_ten   = greater_than(10)


# ===( 4 )===
"""
Какие преимущества дало каррирование?

1) Переиспользование и специализация:
   Одну общую filter_by('category') можно превратить в десяток
   конкретных фильтров: filter_fruits, filter_vegetables и т.д.
   Каждый — самостоятельная функция, готовая к передаче в map/filter.

2) Композиция:
   Каррированные функции удобно комбинировать как строительные
   блоки из маленьких функций от одного аргумента.

3) Частичное применение без явных lambda:
   filter_by_category = filter_by('category') короче и декларативнее,
   чем lambda value: filter_by('category')(value).

4) Читаемость в pipeline-стиле:
   filter_by('category')('fruit')(items) читается как
   последовательность шагов, а не как одна большая формула.

5) Тестируемость:
   Каждый уровень каррирования проверяется отдельно.

Можно ли было обойтись без каррирования?

Да. Минимально достаточно одной функции от трёх аргументов:

    def filter_by(key, value, items): ...

Плюс lambda или partial там, где нужно частичное применение.
Каррирование — это не про новую функциональность, а про удобство
композиции и стиль. В Python оно не является идиоматическим
по умолчанию (в отличие от Haskell), поэтому применяется точечно.

Замечание:
    partial(filter_by, 'category') для каррированной filter_by
    даёт TypeError, потому что partial фиксирует первые
    позиционные аргументы ОДНОЙ функции, а каррированная
    filter_by принимает ровно один аргумент (key).
    Для каррированной функции нужен прямой вызов:
        filter_by_category = filter_by('category')
    partial же уместен для «плоских» функций:
        filter_by_category_p = partial(filter_by_raw, 'category')
"""


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
