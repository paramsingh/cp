n = int(input())
seen = [0 for _ in range(100001)]
arr = list(map(int, input().split()))
notseen = []

for i in arr:
    seen[i] += 1

for i in range(1, n+1):
    if seen[i] == 0:
        notseen.append(i)

for i in range(n):
    if seen[arr[i]] > 1 or arr[i] > n:
        nxt = notseen.pop()
        print(nxt, end = " ")
        seen[nxt] += 1
        seen[arr[i]] -= 1
    else:
        print(arr[i], end = " ")
