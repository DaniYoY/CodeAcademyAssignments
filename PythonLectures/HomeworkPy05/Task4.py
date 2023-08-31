# 4. Anagram Checker
# Description: Write a function that checks if two given words are anagrams of each other.
# Example Input: "listen", "silent"
# Example Output: True

def is_anagram(str1: str, str2: str) -> bool:
    str1 = sorted(str1)
    str2 = sorted(str2)
    return str1 == str2


assert is_anagram("listen", "silent") is True
assert is_anagram("listen", "sile") is False
