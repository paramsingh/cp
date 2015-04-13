n, x, l, r = map(int, raw_input().split())
for i in range(x):
    print (l, r), "\t", (min(l,r), max(l,r))
    l = (l+7) % (n-1)
    r = (r+11) % n
