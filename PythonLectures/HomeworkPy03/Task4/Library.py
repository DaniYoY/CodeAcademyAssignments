# Library Class: The main class that combines all the others,
# containing lists of books, users, and librarians.
# It should have methods to perform various library tasks like
# searching books, checking out books, returning books, managing users, etc.
from User import *
from Book import *
from Transation import *
from Librarian import *
from enum import Enum


class Library:
    __all_books = set()
    __books = dict()
    __users = set()

    UserType = Enum('User type', ["LIBRARIAN", "READER"])

    def __init__(self):
        Library.__users.add(Librarian())

    def add_book(self, librarian_name, librarian_id, book_author, book_isbn, book_title, quantity, ):
        current_librarian = next((user for user in Library.__users if user == Librarian(librarian_name, librarian_id)),
                                 'No such librarian')
        new_book = Book(book_title, book_author, book_isbn)
        if new_book not in Library.__books and isinstance(current_librarian, Librarian):
            current_librarian.add_book(Library.__books, new_book, quantity)
            Library.__all_books.add(new_book)
            Transaction(current_librarian, new_book, TransactionType.BOOK_ADDITION)



# CHECK_OUT = auto(),
# RETURN = auto(),
# BOOK_REMOVAL_FROM_LIB = auto(),
# BOOK_ADDITION = auto(),
# USER_SIGN_UP = auto(),
# USER_REMOVAL = auto()

a = Library()
a.add_book("Generic Librarian", 23, "TJ", "489464889", "Home", 10)
for x in Transaction.get_all_transactions():
    print(x)
