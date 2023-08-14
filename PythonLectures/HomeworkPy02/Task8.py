# .Lambda Function to Sort a List of Tuples
# Write a lambda function that takes a list of tuples and sorts them by the second element.
# Input: [(1, 2), (3, 1), (5, 0)]
# Output: [(5, 0), (3, 1), (1, 2)]

def sort_tuples(tuple_list):
    return sorted(tuple_list, key=lambda element: element[1])


# test
print(sort_tuples([(1, 2), (3, 1), (5, 0)]))
