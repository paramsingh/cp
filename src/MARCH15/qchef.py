n, m, k = map(int, raw_input().split())
a = map(int, raw_input().split())
same_growth = []
for index, num in enumerate(a):
    for j in range(index+1, n):
        if a[j] == num:
            same_growth.append((index+1, j+1))
for term in range(k):
    li, ri = map(int, raw_input().split())
    max_diff = 0
    for pair in same_growth:
        if li <= pair[0] <= ri and li <= pair[1] <= ri:
            diff = abs(pair[0]-pair[1])
            if diff > max_diff:
                max_diff = diff
    print max_diff
