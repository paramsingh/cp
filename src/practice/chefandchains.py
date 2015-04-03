# http://www.codechef.com/FEB15/problems/CHEFCH
terms = int(raw_input())
for i in range(terms):
	string = raw_input()
	length = len(string)
	a = ''.join(map(lambda x: "+" if x%2 else '-', range(length)))
	b = ''.join(map(lambda x: "+" if x%2 else '-', range(1,length+1)))
	counters = [0,0]
	for index,ch in enumerate(string):
		if ch == a[index]:
			counters[0] += 1
		if ch == b[index]:
			counters[1] += 1
	if counters[0] < counters[1]:
		print counters[0]
	else:
		print counters[1]