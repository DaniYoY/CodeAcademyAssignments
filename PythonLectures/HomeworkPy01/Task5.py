# Task 5:
# Description: Write a Python program that counts how many times each letter appears in a given sentence. Ignore case, spaces, and
# punctuation.
# Example:
# Input: "Hello, World!"
# Output: {'h': 1, 'e': 1, 'l': 3, 'o': 2, 'w': 1, 'r': 1, 'd': 1}
sentence = input("Enter  sentence: ")
charDict = dict()
n = 0
for char in sentence:
    if char.isalnum():
        if char.lower() in charDict:
            charDict[char.lower()] += 1
        else:
            charDict[char.lower()] = 1
print(charDict)
