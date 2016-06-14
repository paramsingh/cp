from __future__ import print_function
x, n = raw_input().split('=')
n = int(n)
x = x.split('?')
z = []
for ch in x:
    if ch.strip() == '+' or ch.strip() == '-':
        z.append(ch.strip())
plus = 1
minus = 0
for ch in z:
    if ch == '+':
        plus += 1
    else:
        minus += 1

pvals = [1 for _ in range(plus)]
nvals = [1 for _ in range(minus)]
req = n - plus + minus
if req > 0:
    for index, x in enumerate(pvals):
        if x + req > n:
            pvals[index] = n
            req -= n - x
        else:
            pvals[index] = x + req
            req = 0
elif req < 0:
    req = -req
    for index, x in enumerate(nvals):
        if x + req > n:
            nvals[index] = n
            req -= n - x
        else:
            nvals[index] = x + req
            req  = 0

if req != 0:
    print("Impossible")
else:
    c = 0
    c1 = 0
    print("Possible")
    print(pvals[c], end = " ")
    c += 1
    for ch in z:
        print(ch, end = " ")
        if ch == '+':
            print(pvals[c], end = " ")
            c += 1
        else:
            print(nvals[c1], end = " ")
            c1 += 1
    print("= {}".format(n))

