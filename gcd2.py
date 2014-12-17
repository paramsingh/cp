# http://www.codechef.com/problems/GCD2

# Using Python here isn't cheating right? ;)

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)

t = int(raw_input())
while t:
	line = raw_input().split()
	a = int(line[0])
	b = int(line[1])
	print gcd(a, b)
	t -= 1