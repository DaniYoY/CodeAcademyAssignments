# 9.Generator to Yield Powers of Two
# Write a generator function that yields the powers of two up to n.
# Input: 4
# Output: 1, 2, 4, 8

def yield_power_of_twos(num):
    for current in range(num):
        yield str(2 ** current)


user_input = int(input())
result = ", ".join(yield_power_of_twos(user_input))
print(result)
