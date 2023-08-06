# Task 3:
# Description: Write a program that outputs the string representation of numbers from 1 to n. But for multiples of three, it should output
# "Fizz" instead of the number, and for the multiples of five output "Buzz". For numbers which are multiples of both three and five
# output "FizzBuzz".
# Example:
# Input: 15
# Output: 1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz

a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
for num in a:
    b = ''
    if num % 3 == 0 or num % 5 == 0:

        if num % 3 == 0:
            b += 'Fizz'
        if num % 5 == 0:
            b += 'Buzz'
        print(b)
    else:
        print(num)
