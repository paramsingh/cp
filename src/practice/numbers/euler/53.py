c = [[0 for _ in range(101)] for _ in range(101)]

for i in range(101):
    c[i][0] = 1
    c[i][1] = i

mil = 10**6
ans = 0
for i in range(2, 101):
    for j in range(2, i+1):
        c[i][j] = c[i-1][j] + c[i-1][j-1]
        if c[i][j] > mil:
            ans += 1
print ans

