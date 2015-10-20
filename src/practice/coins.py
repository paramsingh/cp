memo = {}
def func(x):
    if x in memo:
        return memo[x]
    f = 0
    if x == 1:
        f = 1
    elif x > 1:
        f = max(x, func(x/2) + func(x/3) + func(x/4))
    memo[x] = f
    return f

while True:
    try:
        n = int(raw_input())
    except:
        break
    print func(n)

