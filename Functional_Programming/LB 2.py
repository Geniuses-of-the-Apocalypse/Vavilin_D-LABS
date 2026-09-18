from fastapi import FastAPI, HTTPException
import csv
import uvicorn

app = FastAPI(title="FASTAPI для анализа CSV")

CSV_FILE = """\
item,quantity,price
tank,14.0,1020.5
plane,19.0,306.4
car,10.0,124.3
tractor,24.0,250.3
"""

@app.get("/data")
def parse_csv_endpoint():
    return list(csv.DictReader(CSV_FILE.splitlines()))

@app.get("/revenue")
def compute_revenue_endpoint():
    rows = list(csv.DictReader(CSV_FILE.splitlines()))
    try:
        total = sum(float(x["quantity"]) * float(x["price"]) for x in rows)
        return {"revenue": total}
    except (ValueError, KeyError) as e:
        raise HTTPException(status_code=500, detail=str(e))

@app.get("/top-item")
def top_item_endpoint():
    rows = list(csv.DictReader(CSV_FILE.splitlines()))
    if not rows:
        raise HTTPException(status_code=404, detail="Нет данных")
    try:
        return max(rows, key=lambda x: float(x["quantity"]) * float(x["price"]))
    except (ValueError, KeyError) as e:
        raise HTTPException(status_code=500, detail=str(e))

# === ЗАПУСК СЕРВЕРА ===
if __name__ == "__main__":
    uvicorn.run(app, host="127.0.0.1", port=8000)
