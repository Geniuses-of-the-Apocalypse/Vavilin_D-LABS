from types import MappingProxyType
from functools import partial

# ===( 1 )===
FILTER_BY = lambda key: lambda value: lambda items: tuple(
    item for item in items if item.get(key) == value
)

print(FILTER_BY("category")("electronics")
    ([{"name": "Монитор",   "category": "electronics", "price": 300},
    {"name": "Куртка",    "category": "clothes",     "price": 150},
    {"name": "Клавиатура", "category": "electronics", "price": 70},
    {"name": "Шарф",      "category": "clothes",     "price": 25}]))

# ===( 2 )===
print(((lambda key: lambda value: lambda items: tuple(item for item in items if item.get(key) == value)("category"))("tools"))(FILTER_BY))

# ===( 3 )===
GREATER_THAN = lambda threshold: lambda x: x > threshold

print(*(filter(GREATER_THAN(3), [2, 7, 14, 4, 21, 9, 16, 1])))
