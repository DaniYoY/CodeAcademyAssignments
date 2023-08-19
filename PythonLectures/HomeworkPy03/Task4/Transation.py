# Transaction Class: Represents a transaction in the library, such as
# checking out or returning a book. Includes details about the user, book,
# transaction type, date, etc.
from _datetime import datetime
from enum import Enum, auto


class TransactionType(Enum):
    CHECK_OUT = auto(),
    RETURN = auto(),
    BOOK_REMOVAL_FROM_LIB = auto(),
    BOOK_ADDITION = auto(),
    USER_SIGN_UP = auto(),
    USER_REMOVAL = auto()

class Transaction:

    _all_transactions = list()

    def __init__(self, librarian, book, type, user=None):
        self.__librarian = librarian
        self.__book = book
        self.__type = TransactionType(type)
        self.__date = datetime.now()
        self.__user = user
        Transaction._all_transactions.append(self)

    def __str__(self):
        return ("At {0} librarian {1} made {2}, user: {3} for book: {4}"
                .format(self.__date, self.__librarian, self.__type, self.__user, self.__book))

    def add_transaction(self, transaction):
        Transaction._all_transactions.append(transaction)

    @classmethod
    def get_all_transactions(cls):
        return cls._all_transactions



