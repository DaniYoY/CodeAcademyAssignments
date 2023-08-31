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


assert validate_parentheses('{[]}') is True
assert validate_parentheses('') is False
assert validate_parentheses('{[a]}') is False
