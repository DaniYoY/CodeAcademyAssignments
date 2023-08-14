# 15.Generator for Geometric Progression
# Write a generator function that yields a geometric progression with a given start, ratio, and length.
# Input: 2, 3, 4
# Output: 2, 6, 18, 54

def generate_geometric_progression(start, ratio, length):
    for _ in range(length):
        yield str(start)
        start *= ratio


# test
result = ",".join(generate_geometric_progression(2, 3, 4))
print(result)
