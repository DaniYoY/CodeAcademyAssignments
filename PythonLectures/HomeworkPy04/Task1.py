# 1. Задача: Създайте клас BankAccount, който да инкапсулира баланса и позволява депозиране и теглене след проверка на PIN код.
# Вход: PIN 1234, депозит 100, теглене 50
# Изход: баланс 50
import random


class BankAccount:
    __all_account_numbers: [int] = list()

    @classmethod
    def generate_pin(cls) -> int:
        return random.randint(1000, 9999)

    @classmethod
    def generate_account_number(cls) -> int:
        sample = random.randint(100000, 999999)
        if sample in BankAccount.__all_account_numbers:
            return BankAccount.generate_account_number()
        BankAccount.__all_account_numbers.append(sample)
        return sample

    def __init__(self):
        self.__number: int = BankAccount.generate_account_number()
        self.__pin: int = BankAccount.generate_pin()
        self.__balance: float = 0
        # printing for testing
        print(self)

    @property
    def number(self):
        return self.__number

    def deposit(self):
        self.validate_account()
        amount = float(input('Please enter amount for deposit: '))
        self.__balance += amount
        print("Current balance is ", self.__balance)

    def withdraw(self):
        self.validate_account()
        amount = float(input('Please enter amount for withdrawal: '))
        if self.__balance < amount:
            raise ValueError("You poor! No money")
        else:
            self.__balance -= amount
            print("Current balance is ", self.__balance)

    def validate_account(self):
        pin = int(input("Please enter your account pin: "))
        if self.__pin != pin:
            raise ValueError("Wrong account")

    def __str__(self):
        return str(self.__number) + ' ' + str(self.__pin)


test_account = BankAccount()
bank_accounts: [BankAccount] = [test_account]

input_data = input()
current_account = next(filter(lambda account: account.number == int(input_data), bank_accounts), None)
try:
    if current_account is None:
        print('No account found')
    else:
        current_account.deposit()
        current_account.withdraw()
except ValueError as ex:
    print(ex.args)
