# 8.Custom ZIP Function
#
# Description: Implement a generator that behaves like
# the built-in zip function, taking two or more iterables and returning tuples.
# Example Input: [1, 2], [3, 4]
# Example Output: (1, 3), (2, 4)

def convert_to_tuple(*iterables):
    max_range = 0
    for i in iterables:
        max_range = max(max_range, len(i))
    dict_container: [int, list] = dict()
    for i in range(max_range):
        is_value_not_init = True
        for iterable in iterables:
            if is_value_not_init:
                dict_container[i] = list()
            if len(iterable) > i:
                is_value_not_init = False
                dict_container[i].append(iterable[i])

    for i in dict_container:
        yield tuple(dict_container[i])


result =[]
for i in convert_to_tuple([1, 2], [3, 4], range(5)):
    result.append(i)
print(result.__str__()[1:-1])
