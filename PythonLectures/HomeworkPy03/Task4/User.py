# User Class: Represents library users (members) with information like
# name, member ID, current checkouts, etc.
from multipledispatch import dispatch

import Book


class User:
    __memberID = 0
    __no_such_book_exception = "There is no such book for user to return"
    __invalid_id_input = 'User id must be int or bigger number then current'

    def __init__(self, name: str, new_id: int = None):
        self._name = name
        if new_id is None:
            self.__set_id()
        elif isinstance(id, int) and new_id > User.__memberID:
            self._id = new_id
            User.__memberID += new_id + 1
        else:
            raise ValueError(User.__invalid_id_input)
        self._current_checkouts: [Book] = list()

    def __set_id(self):
        self._id = User.__memberID
        User.__memberID += 1

    def get_id(self) -> int:
        return self._id

    def return_book(self, book: Book.Book):
        if self._current_checkouts.count(book) == 0:
            raise ValueError(User.__no_such_book_exception)
        else:
            self._current_checkouts.remove(book)

    def check_out_book(self, book: Book.Book):
        self._current_checkouts.append(book)

    def are_all_books_returned(self) -> bool:
        return len(self._current_checkouts) == 0

    def __str__(self):
        return "{0} {1}".format(self._id, self._name)

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            return self._name == other._name and self._id == other._id
        return False

    def __hash__(self):
        return hash((self.__class__.__name__, self._name, self._id))
