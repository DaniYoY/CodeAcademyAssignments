# 2. Задача: Реализирайте клас Person, който инкапсулира личните данни и предоставя методи за промяна само след валидация с
# парола.
# Вход: парола "secret", промяна на имейл
# Изход: новият имейл
from enum import Enum


class PersonalData:
    fields = Enum("Fields", ["first name", "surname", "social number", "email", "race"])

    def __init__(self, fname: str, surname: str, snumber: int, email: str, race: str):
        self.__first_name: str = fname
        self.__surname: str = surname
        self.__social_number: int = snumber
        self.__email: str = email
        self.__race: str = race

    def update(self, val: str | int, field_type: str | int):
        setter_dict = {
            PersonalData.fields(1): self.set_first_name,
            PersonalData.fields(2): self.set_surname,
            PersonalData.fields(3): self.set_social_number,
            PersonalData.fields(4): self.set_email,
            PersonalData.fields(5): self.set_race,
        }
        if type(field_type) is int:
            setter_dict[PersonalData.fields(field_type)](val)

        if type(field_type) is str:
            setter_dict[PersonalData.fields[field_type.lower()]](val)

    def set_first_name(self, val: str):
        self.__first_name = val

    def set_surname(self, val: str):
        self.__surname = val

    def set_social_number(self, val: int):
        self.__social_number = val

    def set_email(self, val: str):
        self.__email = val

    def set_race(self, val: str):
        self.__race = val

    def __str__(self) -> str:
        return str(f'{self.__first_name} {self.__surname} {self.__email} {self.__social_number} {self.__race}')


class Person:
    def __init__(self, first_name: str, surname: str, social_num: int, email: str, race: str):
        self.__data: PersonalData = PersonalData(first_name, surname, social_num, email, race)
        self.__password: str = self.create_password()

    @staticmethod
    def create_password() -> str:
        while True:
            password_1 = input("Please create password: ")
            password_2 = input("Please repeat password: ")
            if password_1 == password_2:
                return password_1
            else:
                print("passwords don't match! try again")

    def set_data(self, val: str | int, field_type: int | str):
        if self.__validate_password():
            self.__data.update(val, field_type)

    def __validate_password(self) -> bool:
        sample_password = input('Please enter password: ')
        return self.__password == sample_password

    def __str__(self) -> str:
        return str(self.__data)


test = Person('na', 'naoff', 475, 'dsda@fa.com', 'purple')
print(test)
test.set_data(45, 3)
print(test)
test.set_data('na.naoff@nanof.com', 'email')
print(test)
