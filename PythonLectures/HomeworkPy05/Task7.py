# 7. Number to English Words
# Description: Convert a non-negative integer to its English words representation.
# Example Input: 12345
# Example Output: "Twelve Thousand Three Hundred Forty Five"
from enum import Enum


def convert_num_to_text(number: int) -> str:
    """
    :param integer number:
    :return: string representation of the number, supports all numbers between -999 sextillion and 999 sextillion
    """

    if number == 0:
        return 'Zero'
    # setting up negative numbers, this is invoked at end of function
    is_negative_number = False
    if number < 0:
        is_negative_number = True
        number *= -1

    num_ks = Enum('ks', [' ', 'thousand', 'million', 'billion', 'trillion', 'quadrillion', 'quintillion', 'sextillion']
                  , start=0)
    ks_index = 0

    def convert_three_digit_num_to_text(number: int) -> str:
        num_list_1_to_19 = Enum('enum_list', [' ', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight',
                                              'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen',
                                              'sixteen', 'seventeen', 'eighteen', 'nineteen'],
                                start=0)
        num_tens = Enum('enum_tens', ['twenty', 'thirty', 'forty', 'fifty', 'sixty',
                                      'seventy', 'eighty', 'ninety'],
                        start=2)

        result = ''
        num = number % 1000
        while num != 0:
            if num % 100 < 20:
                result = num_list_1_to_19(num % 100).name.capitalize() + ' ' + result
                num //= 100
            else:
                result = num_list_1_to_19(num % 10).name.capitalize() + ' ' + result
                num //= 10
                result = num_tens(num % 10).name.capitalize() + ' ' + result
                num //= 10
            if num > 0:
                result = 'Hundred' + ' ' + result
        return result.strip()

    result = ''
    while number != 0:
        try:
            result = num_ks(ks_index).name.capitalize() + ' ' + result
        except ValueError:
            return 'Number is too big'
        ks_index += 1
        result = convert_three_digit_num_to_text(number % 1000) + ' ' + result
        number //= 1000
    if is_negative_number:
        result = 'Minus ' + result
    return result.strip()


assert convert_num_to_text(901) == 'Nine Hundred One'
assert convert_num_to_text(10) == 'Ten'
assert convert_num_to_text(0) == 'Zero'
assert convert_num_to_text(100) == 'One Hundred'
assert convert_num_to_text(20) == 'Twenty'
assert convert_num_to_text(28) == 'Twenty Eight'
assert convert_num_to_text(999) == 'Nine Hundred Ninety Nine'
assert convert_num_to_text(12345) == 'Twelve Thousand Three Hundred Forty Five'
assert convert_num_to_text(-12345) == 'Minus Twelve Thousand Three Hundred Forty Five'
assert convert_num_to_text(1777666555444333111120345) == 'Number is too big'
assert convert_num_to_text(444333111120345) == ('Four Hundred Forty Four Trillion Three Hundred Thirty Three Billion '
                                                'One Hundred Eleven Million One Hundred Twenty Thousand Three Hundred'
                                                ' Forty Five')
