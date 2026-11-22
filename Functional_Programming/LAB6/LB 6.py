from typing import Any

# ===( 1 )===
def totals(orders): return list(map(lambda o: o["total"], orders))

# ===( 2 )===
class Box:
    def __init__(self, v): self.v = v
    def map(self, f): return Box(f(self.v)) if self.v is not None else Box(None)
    def val(self): return self.v

# ===( 3 )===
def find(orders, oid): return Box(next((o for o in orders if o["id"] == oid), None))

# ===( 4 )===
def laws():
    b = Box(10); f = lambda x: x + 5; g = lambda x: x * 2
    return b.map(lambda x: x).val() == b.val(), b.map(f).map(g).val() == b.map(lambda x: g(f(x))).val()

# ===( main )===
if __name__ == "__main__":
    data = [{"id": 1, "total": 150.0}, {"id": 2, "total": 300.5}]
    print("1:", totals(data))          
    print("\n2:", find(data, 2).map(lambda o: o["total"]).val())
    print("\n3:", find(data, 99).val())  
    print("\n4:", laws())         
