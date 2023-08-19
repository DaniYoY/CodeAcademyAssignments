# User Class: Represents library users (members) with information like
# name, member ID, current checkouts, etc.


class User:
    __memberID = 0
    __no_such_book_exept = "There is no such book for user to return"
    __invalid_id_input = 'User id must be int'
    def __init__(self, name, id=None):
        self._name = name
        if id is None:
            self.__set_id()
        elif isinstance(id, int):
            self._id = id
        else:
            raise ValueError(User.__invalid_id_input)
        self._current_checkouts = dict()

    def __set_id(self):
        self._id = User.__memberID
        User.__memberID += 1


    def return_book(self, book):
        if self._current_checkouts[book] == 0:
            raise ValueError(User.__no_such_book_exept)
        else:
            self._current_checkouts[book] -= 1

    def check_out_book(self, book):
        if self._current_checkouts[book] == 0:
            self._current_checkouts[book] = 1
        else:
            self._current_checkouts[book] += 1

    def __str__(self):
        return "{0} {1}".format(self._id, self._name)

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            return self._name, self._id == other._name, other._id
        return False

    def __hash__(self):
        return hash((self.__class__.__name__, self._name, self._id))
