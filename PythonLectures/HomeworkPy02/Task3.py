# 3.Nested Function for Calculating Factorial
# Write a function that contains a nested function to calculate the factorial of a number.
# Input: 5
# Output: 120

def factorial(num):
    if num == 1:
        return 1
    return factorial(num -1) * num


inputNumber = int(input())
print(factorial(inputNumber))
