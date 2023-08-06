# Task 4:
# Description: Given a list, write a Python program to rotate the list by k positions. Try to solve this without using extra space.
# Example:
# Input: List = [1, 2, 3, 4, 5, 6], k = 2
# Output: [3, 4, 5, 6, 1, 2]

list1 = [1, 2, 3, 4, 5, 6, 7, 8]
k = int(input("Enter a step: "))
firstIndex = 0
print(list1)
for n in range(k):
    list1.append(list1[firstIndex])
    list1.pop(firstIndex)
print(list1)




