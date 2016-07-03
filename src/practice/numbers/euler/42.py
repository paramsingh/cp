triangle = set()
s = 0
for i in range(1, 1000):
    s += i
    triangle.add(s)
ans = 0
for _ in range(1786):
    word = raw_input()
    x = 0
    for ch in word:
        x += ord(ch) - ord('A') + 1
    if x in triangle:
        ans += 1
print ans
