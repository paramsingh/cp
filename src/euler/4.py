import sys
mx = 0
for i in range(999, 99, -1):
    for j in range(999, 99, -1):
        if str(i*j) == str(i*j)[::-1]:
            mx = max(mx, i*j)
print mx
