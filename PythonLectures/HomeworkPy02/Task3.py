# 3.Nested Function for Calculating Factorial
# Write a function that contains a nested function to calculate the factorial of a number.
# Input: 5
# Output: 120

# def factorial(num):
#     if num == 1:
#         return 1
#     return factorial(num -1) * num

def factorial(num):

    def multiply(num1, num2):
        return num1 * num2

    if num == 1:
        return 1

    result = 0
    multiplicator1, multiplicator2 = 1, 1
    for number in range(num):
        result = multiply(multiplicator1, multiplicator2)
        multiplicator1, multiplicator2 = result, multiplicator2 + 1
    return result

inputNumber = int(input())
print(factorial(inputNumber))
