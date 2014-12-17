# http://www.codechef.com/problems/SNAPE

def maximum(ls, b):
	return ((ls**2) + (b**2))**0.5

def minimum(ls, b):
	return ((ls**2) - (b**2))**0.5

t = int(raw_input())
while t:
	line = raw_input().split()
	b = int(line[0])
	ls = int(line[1])
	print minimum(ls, b), maximum(ls, b)
	t -= 1