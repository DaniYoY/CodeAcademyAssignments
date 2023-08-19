# 10*.Lexicographic Permutations Generator
#
# Description: Write a generator to yield all lexicographically ordered
# permutations of a given string.
# Example Input: “ABC”
# Example Output: “ABC”, “ACB”, “BAC”, “BCA”, “CAB”, “CBA”

import itertools


# ver 1
def get_permutations(string_input):
    for char_list in list(itertools.permutations(string_input)):
        yield "".join(char_list)


result = []
for i in get_permutations("ABCDE"):
    result.append(i)
print(result.__str__()[1:-1])


# ver 2
def permutate(string_input):
    string_as_list = [char for char in string_input]
    result = set()

    def traverse(char_list, start_index, end_index):
        if start_index == end_index:
            result.add(''.join(char_list))
            return

        for i in range(start_index, end_index):
            for j in range(start_index + 1, end_index):
                char_list[i], char_list[j] = char_list[j], char_list[i]
                traverse(char_list, i+1, end_index)
                result.add(''.join(char_list))
                char_list[i], char_list[j] = char_list[j], char_list[i]
        return

    traverse(string_as_list, 0, len(string_as_list))
    return result


print(permutate("ABCDE").__str__()[1:-1])
