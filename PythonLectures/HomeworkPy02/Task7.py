# 7.Nested functins for arithmetic operations
# write a function containing nested funtions for addition, substraction, multiplication and division.
# The outer function should take two numbers and an operator as input
# and return the result
# Input: 10,5,"add"
# Output: 15

def complete_arithmetic_op(num1, num2, operation):
    def add(num1, num2):
        return num1 + num2

    def multiply(num1, num2):
        return num1 * num2

    def divide(num1, num2):
        return num1 / num2

    def subtract(num1, num2):
        return num1 - num2

    if operation == "add":
        return add(num1, num2)
    elif operation == "multuply":
        return multiply(num1, num2)
    elif operation == "subtract":
        return subtract(num1, num2)
    elif operation == "divide":
        return divide(num1, num2)


user_input = input()
input_list = user_input.split(",")
print(complete_arithmetic_op(int(input_list[0]),int(input_list[1]), input_list[2][1:-1]))
