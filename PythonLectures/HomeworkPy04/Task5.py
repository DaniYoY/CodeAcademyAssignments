# 5. Задача: Реализирайте клас TemperatureConverter със статични методи за конвертиране между градуси Целзий и
# Фаренхайт.
# Вход: конвертиране на 32 градуса Целзий до Фаренхайт
# Изход: 89.6 градуса Фаренхайт
# Note to all: Requirement is static methods, but because they are used in Task4. I decided to present this solution

class TemperatureConverter:
    @classmethod
    def __celsius_to_fahrenheit(cls, celsius: float):
        result: float = (9 / 5) * celsius + 32
        print("{:.1f} Fahrenheit".format(result))

    @classmethod
    def __fahrenheit_to_celsius(cls, fahrenheit: float):
        result: float = (fahrenheit - 32) * 5 / 9
        print("{:.1f} Celsius".format(result))

    @classmethod
    def convert_temp(cls, temp: float, temp_char: str = 'c'):
        if temp_char != 'c' and temp_char != 'f':
            print('choose between C or F to select what temp you are entering')
        if temp_char.lower() == 'c':
            TemperatureConverter.__celsius_to_fahrenheit(temp)
        if temp_char.lower() == 'f':
            TemperatureConverter.__fahrenheit_to_celsius(temp)


TemperatureConverter.convert_temp(32)
TemperatureConverter.convert_temp(32, 'c')
TemperatureConverter.convert_temp(32, 'f')
TemperatureConverter.convert_temp(32, 'faren')
