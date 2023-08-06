# Task 1:
# Description: Write a Python program that takes a list of integers sorted in ascending order and returns a new list of the
# same length that has the values from the first list raised to the second power. The second list should also be sorted in
# ascending order.
# Example:
# Input: [1, 2, 3, 5, 6, 8, 9]
# Output: [1, 4, 9, 25, 36, 64, 81]

a = [1, 2, 3, 5, 6, 8, 9]
sorted(a)
b = [x ** 2 for x in a]
print(b)

