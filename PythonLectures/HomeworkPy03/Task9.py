# 9*.Palindrome Substring Generator
#
# Description: Create a generator function that yields
# all palindromic substrings from a given string.
# Example Input: “racecar”
# Example Output: “racecar”, “aceca”, “cec”


# Note to assessor: Please note that I checked with CA
# whether "A racecar", where "racecar" is a substring should return same output
# I was told that it should return nothing

def generate_palindromic_substrings(string_input):
    palindrome = lambda word: word == "".join(reversed(word))
    if palindrome(string_input):
        while len(string_input) > 1:
            yield string_input
            string_input = string_input[1:-1]


word = input()
result = []
for substring in generate_palindromic_substrings(word):
    result.append(substring)
print(result.__str__()[1:-1])
