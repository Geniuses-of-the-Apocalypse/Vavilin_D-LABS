from fastapi import FastAPI, HTTPException
from collections import Counter
from typing import Optional
import re
import uvicorn

app = FastAPI(title="FASTAPI для анализа текста")

TEXT = """\
Привет, мир! Hello, world... 42 раза
"""

# ===( 1 )===
def split_words(text: str) -> list[str]:
    return re.findall(r'\w+', text.lower(), flags=re.UNICODE)

# ===( 2 )===
def count_word_frequencies(words: list[str]) -> dict[str, int]:
    return dict(Counter(words))

# ===( 3 )===
def top_word(freq: dict[str, int]) -> Optional[str]:
    return max(freq, key=freq.get) if freq else None


@app.get("/words")
def split_words_endpoint():
    return split_words(TEXT)


@app.get("/frequencies")
def count_frequencies_endpoint():
    words = split_words(TEXT)
    return count_word_frequencies(words)


@app.get("/top-word")
def top_word_endpoint():
    freq = count_word_frequencies(split_words(TEXT))
    if not freq:
        raise HTTPException(status_code=404, detail="Нет данных")
    return {"top_word": top_word(freq)}


# === ЗАПУСК СЕРВЕРА ===
if __name__ == "__main__":
    uvicorn.run(app, host="127.0.0.1", port=8000)
