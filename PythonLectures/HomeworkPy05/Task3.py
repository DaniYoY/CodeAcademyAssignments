# 3. Date Validator
# Description: Write a function that validates a date string in the format "DD/MM/YYYY".
# Example Input: "29/02/2020"
# Example Output: True (2020 was a leap year)

def is_string_date(string: str) -> bool:
    try:
        date_list = string.split('/')
        day = int(date_list[0])
        month = int(date_list[1])
        year = int(date_list[2])
        is_leap_year = year % 4 == 0
        if 1 <= day <= 31 and 1 <= month <= 12 and 0 < year:
            if month == 2:
                if (is_leap_year and day > 29) or (not is_leap_year and day > 28):
                    return False
            if day == 31 and month in [4, 6, 7, 9, 11]:
                return False
            if is_leap_year:
                print(f'True ({year} was a leap year)')
            else:
                print(f'True ({year} was not a leap year)')
            return True
        else:
            return False
    except:
        return False


# reg year on 29th February
assert is_string_date("29/02/2023") is False
# leap year outside February
assert is_string_date("30/02/2024") is False
# leap year in February
assert is_string_date("29/02/2020") is True
#  true reg year
assert is_string_date("29/02/2021") is False
# reg year valid date
assert is_string_date("29/09/2020") is True
# reg year negative date
assert is_string_date("-29/09/2020") is False
# reg year invalid date
assert is_string_date("31/09/2024") is False
# parsing exception
assert is_string_date("2d/02/2020") is False
# less elements and parsing exception
assert is_string_date("2dd02/2020") is False
# if less numbers
assert is_string_date("202/2020") is False
