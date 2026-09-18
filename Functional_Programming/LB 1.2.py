import csv
from typing import Optional

CSV_FILE = """\
item,quantity,price
tank,14.0,1020.5
plane,19.0,306.4
car,10.0,124.3
tractor,24.0,250.3
"""

# ===( 1 )===
def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))

# ===( 2 )===
def compute_revenue(rows: list[dict]) -> float:
    return sum(map(lambda x:float(x["quantity"]) * float(x["price"]), rows))


# ===( 3 )===
def top_item(rows: list[dict]) -> Optional[dict]:
    if not rows:
        return None

    def revenue(x: dict) -> float:
        return float(x["quantity"]) * float(x["price"])

    def my_max(items: list[dict]) -> dict:
        # база рекурсии: один элемент — он и есть максимум
        if len(items) == 1:
            return items[0]
        # рекурсивный шаг: max(голова, максимум хвоста)
        head = items[0]
        tail_best = my_max(items[1:])
        return head if revenue(head) >= revenue(tail_best) else tail_best

    return my_max(rows)


# main
rows = parse_csv(CSV_FILE)

print("\n>>Исходные данные:", rows)

print("\n>>Выручка:", compute_revenue(rows))

print("\n>>Максимальная выручка:", top_item(rows))
