# take sorted names as input
ans = 0
for i in range(1, 5164):
    t = raw_input()
    v = 0
    for ch in t:
        v += ord(ch) - ord('A') + 1
    if t == "COLIN":
        print v*i
    ans += v * i
print ans
