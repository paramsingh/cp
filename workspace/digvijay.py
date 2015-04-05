terms = int(raw_input())
for q in range(terms):
    base, mod = map(int, raw_input().split())
    string = raw_input()
    num = 0
    for ch in string:
        num = num * base + int(ch)
        print (num % mod),
    print ""
