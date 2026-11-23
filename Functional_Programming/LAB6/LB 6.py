from typing import Any, Callable

# ===( 1 )===
def totals():
    def run(orders):
        return tuple(map(lambda o: o["total"], orders))
    return run

# ===( 2 )===
class Box:
    def __init__(self, v): self.v = v
    def map(self, f): return Box(f(self.v)) if self.v is not None else Box(None)
    def val(self): return self.v

# ===( 3 )===
def find():
    def run(orders, oid):
        it = iter(filter(lambda o: o["id"] == oid, orders))
        return Box(next(it, None))
    return run

# ===( main )===
if __name__ == "__main__":
    data = [{"id": 1, "total": 150.0}, {"id": 2, "total": 300.5}]

    get_totals = totals()
    find_order = find()

    print("1:", get_totals(data))
    print("\n2:", find_order(data, 2).map(lambda o: o["total"]).val())
    print("\n3:", find_order(data, 99).val())
