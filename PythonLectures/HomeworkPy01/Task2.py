# Task 2:
# Description: You have a list of integers from 0 to n. The numbers are sequential i.e there are no integer gaps between
# them ex. [1,2,3,4,5,6,7]. Sum all the numbers and print their sum.
# Example:
# Input: [1, 2, 3, 4, 5, 6, 7]
# Output: 28

a = [1, 2, 3, 4, 5, 6, 7, 8]
# ver 1
b = 0
for x in a:
    b += x
print(b)
# ver 2
c = sum(a)
print(c)
