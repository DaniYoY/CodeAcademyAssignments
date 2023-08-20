# 11.Writing a Password Strength Checker Function
#
# Description: Write a function to check the strength of a password
# based on criteria like length, use of special characters, etc.
# Example Input: “P@ssw0rd123”
# Example Output: “Strong”
import re
from enum import Enum


def check_password_strength(password: str):
    if len(password) == 0:
        return 'No password is given.'

    acceptable_password_len = 8
    acceptable_passphrase_len = 20
    successful_checks_counter = 0

    checks = [
        re.search('[a-z]', password) is not None,
        re.search('[A-Z]', password) is not None,
        re.search('[0-9]', password) is not None,
        re.search('[-!£$%&*@{}()#+<>|?]', password) is not None,
        len(password) >= acceptable_password_len,
        len(password) >= acceptable_passphrase_len,
    ]

    password_evaluation = Enum("Password Strength",
                               ["Not acceptable", "Very weak", "Weak", "Regular", "Strong", "Very strong"],
                               start=1)

    for check in checks:
        if check:
            successful_checks_counter += 1

    if successful_checks_counter:
        return password_evaluation(successful_checks_counter).name


print(check_password_strength("2"))
print(check_password_strength("2a"))
print(check_password_strength("2aA"))
print(check_password_strength("This is one Very st000ng password!"))
print(check_password_strength("2aA£00000"))
print(check_password_strength("2aA£"))
