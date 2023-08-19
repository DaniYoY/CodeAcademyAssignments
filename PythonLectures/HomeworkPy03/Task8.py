# 8.Custom ZIP Function
#
# Description: Implement a generator that behaves like
# the built-in zip function, taking two or more iterables and returning tuples.
# Example Input: [1, 2], [3, 4]
# Example Output: (1, 3), (2, 4)

def convert_to_tuple(*iterables):
    for iterable in iterables:
        yield tuple(iterable)

        # Note: Another version

        # result = list()
        # for i in iterable:
        #     result.append(i)
        # yield tuple(result)


result =[]
for i in convert_to_tuple([1, 2], [3, 4], range(5)):
    result.append(i)
print(result.__str__()[1:-1])
