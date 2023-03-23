from collections import defaultdict

t = int(input())
for _ in range(t):
    chars = map(int, input()[::])
    freqs = defaultdict(int)
    for char in chars:
        freqs[char] += 1
    max_freq = max(freqs.values())
    if max_freq == 1 or max_freq == 2:
        print(4)
    elif max_freq == 3:
        print(6)
    else:
        print(-1)
