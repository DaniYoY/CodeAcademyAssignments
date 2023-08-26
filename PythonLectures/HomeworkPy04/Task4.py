# 4. Задача: Създайте клас Calculator, който предоставя статични методи за основни аритметични операции.
# Вход: събиране на 5 и 3
# Изход: 8

class Calculator:
    def __init__(self):
        pass

    @staticmethod
    def add(num1, num2):
        return num1 + num2

    @staticmethod
    def multiply(num1, num2):
        return num1 * num2

    @staticmethod
    def divide(num1, num2):
        if num2 == 0:
            raise ZeroDivisionError
        return num1 / num2

    @staticmethod
    def subtract(num1, num2):
        return num1 - num2


calc = Calculator()
print(f'{calc.add(23, 63.5967):.2f}')
print(f'{calc.divide(130, 63.5967):.2f}')
print(f'{calc.multiply(2, 63.5967):.2f}')
print(f'{calc.subtract(23, 63.5967):.2f}')
print(f'{calc.divide(130, 0):.2f}')
