# 10.Lambda Function to Filter Even Numbers
# Write a lambda function that filters even numbers from a given list.
# Input: [1, 2, 3, 4, 5]
# Output: [2, 4]

# version 1
user_input = input()[1:-1].split(",")
numbers = [int(number) for number in user_input]
numbers = list(filter(lambda num: (num % 2 == 0), numbers))
print(numbers)
