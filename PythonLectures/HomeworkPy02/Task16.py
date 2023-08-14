# 16.Function to Compute Power of Variable Arguments
# Write a function that takes a variable number of arguments and returns the result of raising the first argument to the
# power of the rest in order.
# Input: 2, 3, 2
# Output: 64 (i.e., 2^3^2 = 64)

def get_powered_result(number, *args):
    result = number
    for num in args:
        result = result ** num
    return result


# test
print(get_powered_result(2, 3, 2))
