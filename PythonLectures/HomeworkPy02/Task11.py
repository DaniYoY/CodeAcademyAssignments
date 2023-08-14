# 11.Nested Function to Calculate Exponential
# Write a function containing a nested function that calculates the exponential of a number using a given base.
# Input: 2, 3
# Output: 8

def calculate_exponential(input_list):
    numbers = [int(number) for number in input_list]

    def get_powered_number(number, exponent):
        return number ** exponent

    return get_powered_number(numbers[0], numbers[1])


user_input = input().split(",")
print(calculate_exponential(user_input))
