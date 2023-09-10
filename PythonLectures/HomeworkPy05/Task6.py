# 6. Parentheses Validator
# Description: Write a function that checks if a string containing just the characters '(', ')',
# '{', '}', '[', and ']' is valid. The brackets must close in the correct order.
# Example Input: "{[]}"
# Example Output: True
import unittest


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


# version 2
def validate_parentheses_v2(string: str) -> bool:
    if not isinstance(string, str):
        raise ValueError('this is not a str')
    stack = list()
    parentheses_pair = {']': '[', '}': '{', ')': '('}
    for ch in string:
        if ch in '{[(':
            stack.append(ch)
        elif ch in '}])':
            if not stack:
                return False
            if parentheses_pair[ch] == stack[-1]:
                stack.pop()
        else:
            return False

        if not stack and string:
            return True
        else:
            return False


class TestParenthesesValidator(unittest.TestCase):
    def test_if_isinstance_raises_error(self):
        self.assertRaises(ValueError, validate_parentheses_v2, 2)

    def test_if_False_when_string_empty(self):
        self.assertFalse(validate_parentheses_v2(''))

    def test_if_stack_not_emptied(self):
        self.assertFalse(validate_parentheses_v2('{{}'))

    def test_if_string_contains_other_chars(self):
        self.assertFalse(validate_parentheses_v2('{{d}}'))

    def test_if_string_start_with_back_parenthesis(self):
        self.assertFalse(validate_parentheses_v2(']'))

    def test_if_parentheses_match(self):
        self.assertFalse(validate_parentheses_v2('{{[()]}}'))
