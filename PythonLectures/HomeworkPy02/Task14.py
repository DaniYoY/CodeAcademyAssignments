# 14.Nested Functions for String Manipulation
# Write a function containing nested functions to perform various string manipulations like uppercase, lowercase, and
# capitalization.
# Input: "hello", "uppercase"
# Output: "HELLO"

def manipulate_string(string_input, operation):
    if operation == "uppercase":
        return str(string_input).upper()
    elif operation == "lowercase":
        return str(string_input).lower()
    elif operation == "capitalization":
        return str(string_input).capitalize()


#test
print(manipulate_string("hElLo", "capitalization"))
