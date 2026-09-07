import csv
from typing import Optional

CSV_FILE = """"\
date, item, price,
1983-04-01,soda,325.6
2001-03-25,chocopie,194.2
1997-02-13,sup,204.7
"""

# 1
def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))

# 2
def compute_revenue(rows: list[dict]) -> float:
    return sum(int(row["quantity"]) * float(row["price"]) for row in rows)

# 3
def top_item(rows: list[dict]) -> Optional[dict]:
    return max(rows, key=lambda row: int(row["quantity"]) * float(row["price"]), default=None)

# main
rows = parse_csv(CSV_FILE)

print("Исходные данные: ")
print(rows)

print("\n Выручка: ", compute_revenue(rows))

print("\n Макс. выручка: ")
print(top_item(rows))
