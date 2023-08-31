# 1. String Reverser
# Description: Write a function that takes a string as input and returns its reverse.
# Example Input: "hello"
# Example Output: "olleh"

# version 1
def reversing(string: str) -> str:
    string = ''.join(reversed(string))
    return string


assert reversing('hello') == 'olleh'
assert reversing('') == ''


# version 2
def reversing_v2(string: str) -> str:
    result = str()
    for i in range(len(string)):
        result += string[-1-i]
    return result


assert reversing_v2('hello') == 'olleh'
assert reversing_v2('') == ''


# version 3
def reversing_v3(string: str) -> str:
    return string[::-1]


assert reversing_v3('hello') == 'olleh'
assert reversing_v3('') == ''
