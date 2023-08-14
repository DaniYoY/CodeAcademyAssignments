# 1.Simple Lambda Function
# Write a lambda function that takes two numbers and returns their sum.
# Input: 5, 3
# Output: 8
user_input = input()
number_list = [int(x) for x in user_input.split(", ")]
summing_lambda = lambda num1, num2: num1 + num2
print(summing_lambda(number_list[0], number_list[1]))
