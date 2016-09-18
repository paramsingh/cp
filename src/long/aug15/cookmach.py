# Author: Param Singh <paramsingh258@gmail.com>
import math

def power_of_two(a):
    x = math.log(a, 2)
    return x == math.ceil(x)

terms = int(raw_input())
for _ in range(terms):
    a, b = map(int, raw_input().split())
    count = 0
    while not power_of_two(a) and a != 1:
        a /= 2
        count += 1 
    while a != b:
        if a > b:
            a /= 2;
        else:
            a *= 2
        count += 1
    print count
    

