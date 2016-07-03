def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a*b / gcd(a, b)

ans = 1
for i in range(1, 21):
    ans = lcm(ans, i)
print ans

