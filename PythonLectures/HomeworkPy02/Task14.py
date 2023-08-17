# 14.Nested Functions for String Manipulation
# Write a function containing nested functions to perform various string manipulations like uppercase, lowercase, and
# capitalization.
# Input: "hello", "uppercase"
# Output: "HELLO"

def manipulate_string(string_input, operation):
    def to_upper():
        return str(string_input).upper()

    def to_lower():
        return str(string_input).lower()

    def to_capitalization():
        return str(string_input).capitalize()

    if operation == "uppercase":
        return to_upper()
    elif operation == "lowercase":
        return to_lower()
    elif operation == "capitalization":
        return to_capitalization()


#test
print(manipulate_string("hElLo", "capitalization"))
print(manipulate_string("hElLo", "uppercase"))
print(manipulate_string("hElLo", "lowercase"))
