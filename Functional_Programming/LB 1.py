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
    return sum(int(row["quantity"]) * float(row["price"]) for row in rows)

# ===( 3 )===
def top_item(rows: list[dict]) -> Optional[dict]:
    return max(rows, key=lambda row: int(row["quantity"]) * float(row["price"]), default=None)

# === main ===
rows = parse_csv(CSV_FILE)

print(">>Исходные данные: ", rows)

print("\n>>Выручка: ", compute_revenue(rows))

print("\n>>Максимальная выручка: ", top_item(rows))
