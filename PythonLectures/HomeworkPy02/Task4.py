# lambda inside a function
# write a function that takes a number n and returns a lambda function that multiplies its input by n
# Input: 3
# Output: A function that multiplies its input by 3

def get_multiplier_lambda(multiplier):
    print("A function that multiplies its input by ", multiplier)
    return lambda num: num * multiplier


input_number = int(input())
example_number = 8
example_number = get_multiplier_lambda(input_number)(example_number)
