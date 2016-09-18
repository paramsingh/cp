# Bank Robbery
# Author: Param Singh <paramsingh258@gmail.com>

t = int(raw_input())
mil = 1000000000.0
for _ in range(t):
    x = raw_input().split()
    m = int(x[0])
    p = float(x[1])
    if p != 1.0:
        c = mil * (1 - (-p)**m) / (1+p)
        t = mil - c
        print c, t
    else:
        if m % 2 == 1:
            print mil, mil - mil
        else:
            print mil - mil, mil
