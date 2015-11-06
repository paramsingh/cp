t = int(raw_input())
for _ in range(t):
    ans = 0
    a, d, l, r = map(int, raw_input().split())
    beg = a + (l-1)*d
    dup = beg
    terms = r - l + 1
    flag = [False for _ in range(10)]
    count = 0
    s = 0
    while True:
        x = 1 + ((beg - 1) % 9)
        if flag[x]:
            break
        else:
            s += x
            count += 1
            flag[x] = True
            beg += d
    q = terms / count
    z = terms % count
    ans += (q * s)
    for _ in range(z):
        x = 1 + ((dup - 1) % 9)
        ans += x
        dup += d
    print ans
