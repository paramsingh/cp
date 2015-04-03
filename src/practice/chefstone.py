t = int(raw_input())
for i in range(t):
	n,k = map(int, raw_input().split())
	a = map(int, raw_input().split())
	b = map(int, raw_input().split())
	maximum = (k/a[0])*b[0]
	for j in range(n):
		t = (k/a[j])*b[j]
		if t > maximum:
			maximum = t
	print maximum 