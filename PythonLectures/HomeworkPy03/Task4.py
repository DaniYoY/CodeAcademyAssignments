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
import sys

