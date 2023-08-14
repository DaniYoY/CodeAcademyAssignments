# Palindrome checker using lamda
# Write a lambda function tht checks whether given string is a palindrome
# input: "madam"
# output: True

input_string = input()

palindrome = lambda word: word == "".join(reversed(word))
print(palindrome(input_string))

input_len = len(input_string)
for index in range(int(input_len / 2)):
    if input_string[index] != input_string[input_len - 1 - index]:
        print(False)
        break
else:
    print(True)
