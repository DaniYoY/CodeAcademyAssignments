# 13.Lambda Function to Apply Function to List
# Write a lambda function that takes another function and a list and applies the function to every element of the list.
# Input: lambda x: x*2, [1, 2, 3]
# Output: [2, 4, 6]

apply_func_to_list = lambda func, lst: [func(num) for num in lst]

print(apply_func_to_list(lambda x: x * 2, [1, 2, 3]))
