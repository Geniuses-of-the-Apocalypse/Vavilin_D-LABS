import csv
from typing import Optional

CSV_FILE = """\
item,quantity,price
tank,14,1020.5
plane,19,306.4
car,10,124.3
tractor,24,250.3
"""

# ===( 1 )===
def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))

# ===( 2 )===
def compute_revenue(rows: list[dict]) -> float:
    return sum(map(lambda x:int(x["quantity"]) * float(x["price"]), rows))

# ===( 3 )===
def top_item(rows: list[dict]) -> Optional[dict]:
    if not rows:
        return None
    try:
        return max(rows, key=lambda x: int(x["quantity"]) * float(x["price"]))
    except (ValueError, TypeError, KeyError):
        return None

# main
rows = parse_csv(CSV_FILE)

print("\n>>Исходные данные:", rows)

print("\n>>Выручка:", compute_revenue(rows))

print("\n>>Максимальная выручка:", top_item(rows))


# ===( 4 )===

# 1. Функция не имеет побочных эффектов, а значит является Чистой.

# 2. Если в CSV данных окажется пустая строка (строка ввиде проблеов через запятую), то в таком случае программа
# упадёт в ошибку. Это во многом связано с типами int и float, которые не могут принимать пустые строковые 
# значения, вызывая ошибку. Эту проблему можно решить путём создания проверки и подстановки нулей заместо 
# пробелов, однако такой подход может привести к возникновению побочных эффектов, от чего функция перестанет быть
# чистой.

# 3. Функция parse_csv принимает строку типа str и выходит в виде списка list[dict].
# Функция compute_revenue получает на вход список list[dict] и выводит тип float.
# Функция top_item получает на вход список list[dict] и на выходе выдаёт опциональный словарь Optional[dict].
# При этом все функции ожидают, что в каждом словаре есть ключи ввиде "quantity" и "price", также они ожидают,
# ято значения можно преобразовать в int и float, в противном случае это приводит к фатальной ошибке (пункт 2).
