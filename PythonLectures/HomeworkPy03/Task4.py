# 4.Library Management System
#
# Description:
# Develop a Library Management System that includes multiple classes and
# relationships to represent the various entities within a library.
# It should include:
#
# Book Class: Holds details about individual books, including title,
# author, ISBN, availability status, etc.
#
# User Class: Represents library users (members) with information like
# name, member ID, current checkouts, etc.
#
# Librarian Class: A subclass of the user with additional privileges such as
# adding books, managing users, etc.
#
# Transaction Class: Represents a transaction in the library, such as
# checking out or returning a book. Includes details about the user, book,
# transaction type, date, etc.
#
# Library Class: The main class that combines all the others,
# containing lists of books, users, and librarians.
# It should have methods to perform various library tasks like
# searching books, checking out books, returning books, managing users, etc.

from Task4 import *

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



