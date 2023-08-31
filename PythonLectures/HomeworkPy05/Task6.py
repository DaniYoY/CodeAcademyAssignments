# 6. Parentheses Validator
# Description: Write a function that checks if a string containing just the characters '(', ')',
# '{', '}', '[', and ']' is valid. The brackets must close in the correct order.
# Example Input: "{[]}"
# Example Output: True

def validate_parentheses(string: str) -> bool:
    if string is None or string == '':
        return False
    for ch in string:
        if ch not in '{}[]()':
            return False
    return True


# if string is correct
assert validate_parentheses('{[]}') is True
# if string is empty
assert validate_parentheses('') is False
# if string is invalid
assert validate_parentheses('{[a]}') is False
