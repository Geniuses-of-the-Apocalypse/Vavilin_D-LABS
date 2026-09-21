from collections import Counter
from typing import Optional
import re #Regular Extensions

# ===( 1 )===
def split_words(text: str) -> list[str]:
    return re.findall(r'\w+', text.lower(), flags=re.UNICODE)

#===( 2 )===
def count_word_frequncies(words: list[str]) -> dict[str, int]:
    return dict(Counter(words))

#===( 3 )===
def top_word(freq: dict[str, int]) -> Option[str]: #Нужен фикс
    return max(freq, key=freq.get)

# === main ===
print(split_words("Привет, мир! Hello, world... 42 раза"))

print(count_word_frequncies(['mama', 'wash', 'hands', 'mama']))

print(top_word({"мама": 2, "мыла": 1, "раму": 1}))
