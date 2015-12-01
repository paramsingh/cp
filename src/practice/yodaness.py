bit = [0]
maxval = 0

def update(idx, val):
    while idx <= maxval:
        bit[idx] += val
        idx += (idx & (-idx))

def query(idx):
    ans = 0
    while idx > 0:
        ans += bit[idx]
        idx -= (idx & (-idx))
    return ans

t = int(raw_input())
for _ in range(t):
    n = int(raw_input())
    bit = [0 for _ in range(n+3)]
    maxval = n
    yoda = raw_input().split()
    sentence = raw_input().split()
    words = {}
    for index, word in enumerate(sentence):
        words[word] = index + 1
    lst = []
    for word in yoda:
        lst.append(words[word])
    ans = 0
    for i in lst[::-1]:
        ans += query(i-1)
        update(i, 1)
    print ans


