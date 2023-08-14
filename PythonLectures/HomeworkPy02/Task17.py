# 17.Function to Sort Variable Number of Lists
# Write a function that takes a variable number of lists and returns a single list containing all the elements, sorted.
# Input: [3, 1], [5, 2], [4, 0]
# Output: [0, 1, 2, 3, 4, 5]

# version 1
def join_numbers(string_input):
    string_list = str(string_input).split(",")
    result = list(string_list)
    result = [int(num) for num in result]
    result = sorted(result)
    return result


user_input = input()
user_input = user_input.replace("[", "").replace("]", "")
output = join_numbers(user_input)
print(output)


# version 2

def join_numbers_2(*args):
    res = list()
    for lisst in args:
        for num in lisst:
            res.append(num)

    return sorted(res)


print(join_numbers_2([3, 1], [5, 2], [4, 0]))
