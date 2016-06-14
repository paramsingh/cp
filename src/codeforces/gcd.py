a, b = map(int, raw_input().split())
# gcd(a, b) = gcd(b, a % b)

if a == b:
    print a
else:
    print 1
