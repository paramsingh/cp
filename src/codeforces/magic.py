need = []
have = []
a = [0 for _ in range(100100)]
n = 0
k = 0
def valid(val):
    for i in range(n):
        a[i] = need[i] * val
    total = 0
    for i in range(n):
        if a[i] > have[i]:
            total += a[i] - have[i]
    if total > k:
        return 1
    else:
        return 0

n, k = map(int, raw_input().split())
need = map(int, raw_input().split())
have = map(int, raw_input().split())
lo = 0
hi = 10**18
while lo < hi:
    mid = (lo + hi) / 2
    if valid(mid):
        hi = mid
    else:
        lo = mid + 1
print lo-1
