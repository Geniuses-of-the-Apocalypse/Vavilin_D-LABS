from types import MappingProxyType
from functools import partial

# ===( 1 )===
filter_by = lambda key: lambda value: lambda items: tuple(
    item for item in items if item.get(key) == value
)

print(filter_by("category")("electronics")
    ([{"name": "Монитор",   "category": "electronics", "price": 300},
    {"name": "Куртка",    "category": "clothes",     "price": 150},
    {"name": "Клавиатура", "category": "electronics", "price": 70},
    {"name": "Шарф",      "category": "clothes",     "price": 25}]))

# ===( 2 )===
FILTER_BY_CATEGORY = partial(filter_by, "category")
FILTER_CLOTHES = FILTER_BY_CATEGORY("clothes")
FILTER_ELECTRONICS = FILTER_BY_CATEGORY("electronics")

print(FILTER_CLOTHES(
    [{"name": "Монитор",   "category": "electronics", "price": 300},
    {"name": "Куртка",    "category": "clothes",     "price": 150},
    {"name": "Клавиатура", "category": "electronics", "price": 70},
    {"name": "Шарф",      "category": "clothes",     "price": 25}]))

print(FILTER_ELECTRONICS(
    [{"name": "Монитор",   "category": "electronics", "price": 300},
    {"name": "Куртка",    "category": "clothes",     "price": 150},
    {"name": "Клавиатура", "category": "electronics", "price": 70},
    {"name": "Шарф",      "category": "clothes",     "price": 25}]))

# ===( 3 )===
GREATER_THAN = lambda threshold: lambda x: x > threshold
LESS_THAN = lambda threshold: lambda x: x < threshold

print(tuple(filter(GREATER_THAN(3), [2, 7, 14, 4, 21, 9, 16, 1])))
print(tuple(filter(LESS_THAN(10), [2, 7, 14, 4, 21, 9, 16, 1])))
