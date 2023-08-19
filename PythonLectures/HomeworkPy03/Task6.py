# 6. Implement a Custom Range Generator
#
# Description: Create a generator function that mimics
# the built-in range function. It should accept start, stop, and step arguments.
# Example Input: custom_range(2, 10, 2)
# Example Output: 2, 4, 6, 8

# VERSION 1
from multipledispatch import dispatch


@dispatch(int, int, int)
def my_range(start_index, end_index, step=1):
    if type(start_index) is not int or type(end_index) is not int or type(step) is not int:
        raise ValueError("Integer is a MUST")

    num = start_index
    if start_index > end_index and step < 0:
        while num > end_index:
            yield num
            num += step
    elif start_index < end_index and step > 0:
        while num < end_index:
            yield num
            num += step


@dispatch(int, int)
def my_range(end_index, step=1):
    if type(end_index) is not int or type(step) is not int:
        raise ValueError("Integer is a MUST")

    num = 0
    while num < end_index:
        yield num
        num += step


result = []
for i in my_range(10, 3):
    result.append(i)
print(result.__str__()[1:-1])
result.clear()
for i in my_range(5, 35, 7):
    result.append(i)
print(result.__str__()[1:-1])


# END OF VERSION 1
#
# VERSION 2

# def my_range_v2(*,start_index=0, end_index=0, step=1):
def my_range_v2(start_index=0, end_index=0, step=1):
    if type(start_index) is not int or type(end_index) is not int or type(step) is not int:
        raise ValueError("Integer is a MUST")
    if step == 0:
        raise GeneratorExit("Step is 0, this is infinite looping, this I do not support")

    num = start_index

    if start_index > end_index and step < 0:
        while num > end_index:
            yield num
            num += step
    elif start_index < end_index and step > 0:
        while num < end_index:
            yield num
            num += step


result.clear()
for i in my_range_v2(end_index=10, step=1):
    result.append(i)
print(result.__str__()[1:-1])
result.clear()
for i in my_range_v2(2, 10, 2):
    result.append(i)
print(result.__str__()[1:-1])

result.clear()
print("Test low to high, step -")
for i in my_range_v2(2, 10, -2):
    result.append(i)
print(result.__str__()[1:-1])

result.clear()
print("Test high to low, step +")
for i in my_range_v2(10, 1, 2):
    result.append(i)
print(result.__str__()[1:-1])

result.clear()
print("Test high to low, step -")
for i in my_range_v2(20, 10, -2):
    result.append(i)
print(result.__str__()[1:-1])
