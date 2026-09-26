from dataclasses import dataclass
from enum import Enum, auto
from typing import Generic, TypeVar, Union

# ===( 1 )===
class LoadState(Enum):
    LOADING = auto()
    SUCCESS = auto()
    ERROR = auto()


# ===( 2 )===
@dataclass(frozen=True)
class User:
    name: str
    age: int
    email: str


# ===( 3 )===
T = TypeVar("T")
E = TypeVar("E")

@dataclass(frozen=True)
class Success(Generic[T]):
    value: T

@dataclass(frozen=True)
class Failure(Generic[E]):
    error: E

Result = Union[Success[T], Failure[E]]


def fetch_users_from_api() -> list[User]:
    """Заглушка вместо реального HTTP-запроса."""
    return [
        User(name="Valeriya", age=20, email="nekodai@example.com"),
        User(name="Sophie", age=25, email="waltenari@example.com"),
        User(name="Aegis", age=30, email="persona3@example.com"),
        ]


def load_users() -> Result[list[User], str]:
    users = fetch_users_from_api()
    if not users:
        return Failure("Список пользователей пуст")
    return Success(users)


# === Пример ===
if __name__ == "__main__":
    match load_users():
        case Success(users):
            print(f"Загружено {len(users)} пользователей")
            for u in users:
                print(f"  {u.name}, {u.age}, {u.email}")
        case Failure(err):
            print(f"Ошибка: {err}")
