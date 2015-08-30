# Author: Param Singh <paramsingh258@gmail.com>

t = int(raw_input())
for _ in range(t):
    l = int(raw_input())
    lst = map(int, raw_input().split())
    x = min(lst)
    ans = x * (l-1)
    print ans
