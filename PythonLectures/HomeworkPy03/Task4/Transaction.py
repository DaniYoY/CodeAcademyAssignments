# Transaction Class: Represents a transaction in the library, such as
# checking out or returning a book. Includes details about the user, book,
# transaction type, date, etc.
from _datetime import datetime
from enum import Enum, auto
import Librarian, Book, User


class TransactionType(Enum):
    CHECK_OUT_BOOK = auto(),
    FAILED_CHECK_OUT_BOOK = auto(),
    RETURN_BOOK = auto(),
    BOOK_ADDITION = auto(),
    USER_SIGN_UP = auto(),
    USER_REMOVAL = auto(),
    FAILED_USER_REMOVAL = auto()


class Transaction:

    def __init__(self, librarian: Librarian.Librarian, book: Book.Book,
                 transaction_type: TransactionType, user: User.User = None):
        self.__librarian = librarian
        self.__book = book
        self.__type = TransactionType(transaction_type)
        self.__date = datetime.now()
        self.__user = user

    def get_transaction_type(self) -> TransactionType:
        return self.__type

    def __str__(self):
        return ("At {0} librarian {1} made {2}, user: {3} for book: {4}"
                .format(self.__date, self.__librarian, self.__type.name, self.__user, self.__book))
