# 7.Nested Generator for Flattening Lists
#
# Description: Create a generator that takes a nested list and flattens it.
# Example Input: [[1, 2], [3, 4]]
# Example Output: 1, 2, 3, 4

# version 1
def sep_string_list_input(input_data):
    result = str(input_data)
    result = result.replace('[','').replace(']','')
    result = result.split(', ')
    for string in result:
        yield string


# user_input = input()
#
# result_v1 = []
# for string in sep_string_list_input(user_input):
#     result_v1.append(int(string))
# print(result_v1.__str__()[1:-1])


# version 2
def flatten_lists(list_of_lists):
    result = list()
    for current_list in list_of_lists:
        if isinstance(current_list, list):
            yield current_list
        else:
            raise Exception("This cannot be iterated")
    return result


user_input_as_list = [[1, 2], [3, 4]]
result_v2 = []
for number_list in flatten_lists(user_input_as_list):
    result_v2 += number_list
print(result_v2.__str__()[1:-1])
