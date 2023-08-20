# Book Class: Holds details about individual books, including title,
# author, ISBN, availability status, etc.
from enum import Enum


class BookStatus(Enum):
    OUT_OF_STOCK = 0
    IN_LIBRARY = 1


class Book:

    def __init__(self, title: str, author: str, ISBN: int):
        self.__title = title
        self.__author = author
        self.__isbn = ISBN
        self.__status = BookStatus.IN_LIBRARY

    def change_status(self):

        if self.__status is BookStatus.IN_LIBRARY:
            self.__status = BookStatus.OUT_OF_STOCK
        else:
            self.__status = BookStatus.IN_LIBRARY

    def get_status(self):
        return str(self.__status)

    def get_isbn(self):
        return self.__isbn

    def __hash__(self):
        return hash((self.__title.lower(), self.__author.lower(), self.__isbn))

    def __eq__(self, other):
        if isinstance(other, Book):
            return (self.__title.lower(), self.__author.lower(), self.__isbn
                    == other.__title.lower(), other.__author.lower(), other.__isbn)
        return False

    def __str__(self):
        return ("{0} by {1}, ISBN: {2}"
                .format(self.__title, self.__author, self.__isbn))
