# 2.Generator to Yield Fibonacci Sequence
# Write a generator function that yields the Fibonacci sequence up to n numbers.
# Input: 5
# Output: 0, 1, 1, 2, 3
def fibonacci(n):
    iteration = 0
    num1 = 0
    num2 = 1
    while iteration < n:
        yield str(num1)
        num2 = num1 + num2
        num1 = num2 - num1
        iteration += 1


numInput = int(input())
result = str()
for testNum in fibonacci(numInput):
    result += str(testNum) + ', '
result = result[:-1:]
print(result)
