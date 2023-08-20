# Library Class: The main class that combines all the others,
# containing lists of books, users, and librarians.
# It should have methods to perform various library tasks like
# searching books, checking out books, returning books, managing users, etc.
from User import User
from Book import Book
from Transaction import Transaction, TransactionType
from Librarian import Librarian
from enum import Enum, auto


class UserType(Enum):
    LIBRARIAN = auto()
    READER = auto()


class Library:

    def __init__(self):
        self.__books: [Book, int] = dict()
        self.__users: [UserType, list] = dict([(UserType.LIBRARIAN, list()), (UserType.READER, list())])
        self._all_transactions: [Transaction] = list()

    def __get_librarian_by_id(self, librarian_id: int) -> Librarian:
        current_librarian = next(filter(lambda librn: librn.get_id() == librarian_id,
                                        self.__users[UserType.LIBRARIAN]), None)
        if current_librarian is None:
            raise ValueError("Librarian is not found")
        return current_librarian

    def __get_user_by_id(self, user_id: int) -> User:
        current_user = next(filter(lambda user: user.get_id() == user_id,
                                   self.__users[UserType.READER]), None)
        if current_user is None:
            raise ValueError("User is not found")
        return current_user

    def __get_book_by_isbn(self, isbn: int) -> Book:
        current_book = next(filter(lambda user: user.get_isbn() == isbn,
                                   self.__books), None)
        if current_book is None:
            raise ValueError("Book is not found")
        return current_book

    def add_book(self, librarian_id: int, book_title: str, book_author: str, book_isbn: int, quantity: int):
        """
        Used for when Librarian accepts one or more books
        """
        current_librarian = self.__get_librarian_by_id(librarian_id)
        new_book = Book(book_title, book_author, book_isbn)
        if quantity > 0:
            current_librarian.add_book(self.__books, new_book, quantity)
            self._all_transactions.append(Transaction(current_librarian, new_book, TransactionType.BOOK_ADDITION))
        else:
            raise ValueError("You cannot add such quantity of books")

    def check_out_book(self, librarian_id: int, book_isbn: int, user_id: int):
        """
        Used for when Librarian gives a book to the User
        """
        current_librarian = self.__get_librarian_by_id(librarian_id)
        current_book = self.__get_book_by_isbn(book_isbn)
        current_user = self.__get_user_by_id(user_id)
        if current_librarian.remove_book(self.__books, current_book):
            current_user.check_out_book(current_book)
            self._all_transactions.append(
                Transaction(current_librarian, current_book, TransactionType.CHECK_OUT_BOOK, current_user))
        else:
            self._all_transactions.append(
                Transaction(current_librarian, current_book, TransactionType.FAILED_CHECK_OUT_BOOK, current_user))

    def return_book(self, librarian_id: int, book_isbn: int, user_id: int):
        """
        Used for when Librarian accepts a book from User
        """
        current_librarian = self.__get_librarian_by_id(librarian_id)
        current_book = self.__get_book_by_isbn(book_isbn)
        current_user = self.__get_user_by_id(user_id)
        current_librarian.add_book(self.__books, current_book, 1)
        current_user.return_book(current_book)
        self._all_transactions.append(
            Transaction(current_librarian, current_book, TransactionType.RETURN_BOOK, current_user))

    def sign_up_user(self, librarian_id: int, user_name: str):
        """
        Creates a new User
        """
        current_librarian = self.__get_librarian_by_id(librarian_id)
        current_user = User(user_name)
        self.__users[UserType.READER].append(current_user)
        self._all_transactions.append(
            Transaction(current_librarian, Book('', '', 0), TransactionType.USER_SIGN_UP, current_user))

    def delete_user(self, librarian_id: int, user_id: int):
        """
        Removes a user if user has returned all books
        """
        current_librarian = self.__get_librarian_by_id(librarian_id)
        current_user = self.__get_user_by_id(user_id)
        if current_user.are_all_books_returned():
            current_librarian.remove_user(self.__users[UserType.READER], current_user)
            self._all_transactions.append(
                Transaction(current_librarian, Book('', '', 0), TransactionType.USER_REMOVAL, current_user))
        else:
            self._all_transactions.append(
                Transaction(current_librarian, Book('', '', 0), TransactionType.FAILED_USER_REMOVAL, current_user))

    def get_transactions(self, criteria: int = None) -> list:
        """
        Returns a list of all transactions based on a filter of the Transaction type
        """
        if criteria is None:
            return self._all_transactions
        else:
            return list(filter(lambda crit: crit.get_transaction_type().value == (criteria,), self._all_transactions))

    def initiate_librarians(self):
        """
        Used for creation of test Librarians
        """
        self.__users[UserType.LIBRARIAN].append(Librarian("Libra"))
        self.__users[UserType.LIBRARIAN].append(Librarian("Lili"))
        self.__users[UserType.LIBRARIAN].append(Librarian("Baba"))

        for current_librarian in self.__users[UserType.LIBRARIAN]:
            print(current_librarian)


# CHECK_OUT_BOOK 1
# FAILED_CHECK_OUT_BOOK 2
# RETURN_BOOK 3
# BOOK_ADDITION 4
# USER_SIGN_UP 5
# USER_REMOVAL 6
# FAILED_USER_REMOVAL 7

lib = Library()
lib.initiate_librarians()
lib.add_book(0, "Little Prince", "Antoine de Saint-Exupery", 51498432186, 9)
lib.add_book(1, "Little Prince", "Antoine de Saint-Exupery", 51498432186, 3)
lib.add_book(2, "Where's my cow?", "Pratchett", 895316312, 5)
lib.add_book(2, "Malazan Book of the fallen", "Steven Erikson", 5649841, 1)
lib.add_book(2, "Wheel of Time", "Robert Jordan", 564984121, 2)
print()
for tr in lib.get_transactions():
    print(tr)
print()
lib.sign_up_user(1, "John A")
lib.sign_up_user(1, "John B")
lib.sign_up_user(1, "John B")

lib.delete_user(1, 4)
lib.check_out_book(2, 5649841, 5)
lib.check_out_book(2, 564984121, 5)
lib.delete_user(1, 5)
lib.check_out_book(2, 5649841, 5)
lib.return_book(2, 5649841, 5)

for tr in lib.get_transactions():
    print(tr)
print()
