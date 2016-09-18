n = int(raw_input())
for _ in range(n):
    raw_input()
    lst = map(int, raw_input().split())
    prev = 0
    alloc = 0
    for x in lst:
        if x > prev:
            alloc += x - prev
        prev = x
    print alloc
