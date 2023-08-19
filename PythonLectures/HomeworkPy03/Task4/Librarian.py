# Librarian Class: A subclass of the user with additional privileges such as
# adding books, managing users, etc.

import User


class Librarian(User.User):
    _generic_name = "Generic Librarian"
    __no_such_book_exept = "There is no such book for librarian to remove"
    def __init__(self, name=_generic_name, id=None):
        super().__init__(name, id)

    def add_book(self, library_map, book, quantity):
        if library_map[book] == 0:
            library_map[book] = quantity
        else:
            library_map[book] += quantity

    def add_user(self, user_container, user):
        user_container.add(user)

    def remove_book(self, library_map, book):
        if library_map[book] == 0:
            raise ValueError(Librarian.__no_such_book_exept)
        else:
            library_map[book] -= 1

    def remove_user(self, user_container, user):
        user_container.remove(user)

    def __str__(self):
        return super().__str__()

    def __eq__(self, other):
        return super().__eq__(other)

    def __hash__(self):
        return super().__hash__()
