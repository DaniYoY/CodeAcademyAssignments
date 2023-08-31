#
# 5. Longest Common Prefix
# Description: Write a function that finds the longest common prefix string amongst an array of
# strings.
# Example Input: ["flower","flow","flight"]
# Example Output: "fl"

def get_longest_common_prefix(strings: list[str]) -> str:

    result = ''
    try:
        for i in range(len(strings[0])):
            is_char_to_be_added = True
            current_char = strings[0][i]
            for string in strings:
                if string[i] != current_char:
                    is_char_to_be_added = False
                    break
            if is_char_to_be_added:
                result += current_char
            else:
                break
    except IndexError:
        return result

    return result


# if prefix is smaller than the len of strings
assert get_longest_common_prefix(["flower", "flow", "flight"]) == 'fl'
# if prefix is equal to the len of strings
assert get_longest_common_prefix(["flower", "flow", "flowing"]) == 'flow'
# if there is one element in the list
assert get_longest_common_prefix(["flower"]) == 'flower'
# if list is empty
assert get_longest_common_prefix([]) == ''
# if list elements have no prefix
assert get_longest_common_prefix(["a flower", "flow", "flowing"]) == ''

