from typing import Any, Callable

# ===( 1 )===
def totals(orders):
    def run():
        return map(lambda o: o["total"], orders)
    return run

# ===( 2 )===
class Box:
    def __init__(self, v): self.v = v
    def map(self, f): return Box(f(self.v)) if self.v is not None else Box(None)
    def val(self): return self.v

# ===( 3 )===
def find(orders, oid):
    def run():
        it = iter(filter(lambda o: o["id"] == oid, orders))
        return Box(next(it, None))
    return run

# ===( main )===
if __name__ == "__main__":
    data = [{"id": 1, "total": 150.0}, {"id": 2, "total": 300.5}]

    get_totals = totals(data)       
    find_order = find(data, 2)        

    print("1:", tuple(get_totals()))   
    print("2:", find_order().map(lambda o: o["total"]).val())
    print("3:", find(data, 99)().val())
