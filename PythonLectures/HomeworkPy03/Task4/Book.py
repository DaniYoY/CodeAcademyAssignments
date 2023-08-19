# Book Class: Holds details about individual books, including title,
# author, ISBN, availability status, etc.
from enum import Enum


class Book:
    in_lib = "IN_LIBRARY"
    out_of_st = "OUT_OF_STOCK"
    Status = Enum ("Book status",[in_lib, out_of_st])

    def __init__(self, title, author, ISBN):
        self.__title = str(title)
        self.__author = str(author)
        self.__isbn = str(ISBN)
        self.__status = Book.Status[Book.in_lib]

    def change_status(self):

        if self.__status is Book.Status[Book.in_lib]:
            self.__status = Book.Status[Book.out_of_st]
        else:
            self.__status = Book.Status[Book.in_lib]

    def get_status(self):
        return str(self.__status)

    def __hash__(self):
        return hash((self.__title.lower(), self.__author.lower(), self.__isbn.lower()))

    def __eq__(self, other):
        if isinstance(other, Book):
            return (self.__title.lower(), self.__author.lower(), self.__isbn.lower()
                    == other.__title.lower(), other.__author.lower(), other.__isbn.lower())
        return False

    def __str__(self):
        return ("{0} by {1}, ISBN: {2}"
                .format(self.__title, self.__author, self.__isbn))
