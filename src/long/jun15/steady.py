# test submission, please ignore

cases = int(raw_input())

def choose(n, r):

    def fact(n):
        ans = 1
        for x in range(1, n+1):
            ans *= x
        return ans

    return fact(n) / (fact(n-r) * fact(r))

for _ in range(cases):
    n, m = map(int, raw_input().split())
    req, sums = [], []
    for i in range(m+1):
        req.append(choose(m+i-1, i))
    sums = req[:]
    for i in range(n-1):
        ans = 0
        for index, x in enumerate(sums):
            ans += x
            sums[index] = req[index] * ans
    print sum(sums) % 1000000000


