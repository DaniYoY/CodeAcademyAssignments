# Librarian Class: A subclass of the user with additional privileges such as
# adding books, managing users, etc.

from multipledispatch import dispatch

import Book
import User


class Librarian(User.User):
    _generic_name = "Generic Librarian"
    __no_such_book_exept = "There is no such book for librarian to remove"

    def __init__(self, name: str = _generic_name, new_id: int = None):
        super().__init__(name, new_id)

    def get_id(self) -> int:
        return super().get_id()

    @staticmethod
    def add_book(library_map: dict, book: Book.Book, quantity: int):
        if book not in library_map.keys():
            library_map[book] = quantity
        else:
            library_map[book] += quantity
            key_book = next(filter(lambda x: x == book, library_map.keys()), None)

            if key_book.get_status() == Book.BookStatus.OUT_OF_STOCK:
                key_book.change_status()

    @staticmethod
    def add_user(user_container: list, user: User.User):
        user_container.append(user)

    @staticmethod
    def remove_book(library_map: dict, book: Book.Book) -> bool:
        if book not in library_map.keys():
            raise ValueError(Librarian.__no_such_book_exept)
        elif library_map[book] == 1:
            key_book = next(filter(lambda x: x == book, library_map.keys()), None)
            if key_book.get_status() == Book.BookStatus.IN_LIBRARY:
                key_book.change_status()
            return False
        else:
            library_map[book] -= 1
            return True

    @staticmethod
    def remove_user(user_container: list, user: User.User):
        user_container.remove(user)

    def __str__(self):
        return super().__str__()

    def __eq__(self, other):
        return super().__eq__(other)

    def __hash__(self):
        return super().__hash__()
