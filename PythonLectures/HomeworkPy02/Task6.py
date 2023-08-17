# 6.Generator for Prime Numbers
# write a generator that yields prime numbers up to n.
# Input: 10
# Output: 2,3,5,7

def generate_prime_number(num_upper_border):
    current_num = 2
    # while current_num <= num_upper_border:
    while current_num < num_upper_border:
        for i in range(2, current_num):
            if current_num % i == 0:
                break
        else:
            yield str(current_num)
        current_num += 1


input_number = int(input())
result = ","
result = result.join(generate_prime_number(input_number))
print(result)
