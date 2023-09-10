# 12.Generator for Multiplication Table
# Write a generator function that yields the multiplication expense_table for a given number up to n.
# Input: 3, 5
# Output: 3, 6, 9, 12, 15

def get_multiplication_table(base, multiplicator):
    for number in range(1, multiplicator + 1):
        yield str(number * base)


user_input = input().split(",")
numbers = [int(number) for number in user_input]
result = ", ".join(get_multiplication_table(numbers[0], numbers[1]))
print(result)
