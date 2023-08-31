# 2. Prime Checker
# Description: Write a function that checks if a given number is prime or not.
# Example Input: 7
# Example Output: True
import math


def is_prime(number: float) -> bool:
    if number != int(number) or (int(number) % 2 == 0 and number != 2) or number <= 0:
        return False
    for i in range(2, int(math.sqrt(number))):
        if number % i == 0:
            return False
    return True


assert is_prime(7) is True
assert is_prime(2) is True
assert is_prime(1) is True
assert is_prime(77) is False
assert is_prime(-77) is False
assert is_prime(0) is False
assert is_prime(77.56) is False
