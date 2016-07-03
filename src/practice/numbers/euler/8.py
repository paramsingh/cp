num = raw_input()
mx = 0
for i in range(0, len(num)):
    pr = 1
    for j in range(i, i+13):
        if j >= len(num):
            continue
        pr *= ord(num[j]) - ord('0')
    mx = max(mx, pr)
print mx
