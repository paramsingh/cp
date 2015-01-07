def num_substring(lst, left, right):
	found = [0,0,0]
	last_found = [0,0,0]
	sum_found = 0
	for i in range(left, right+1):
		res = int(lst[i-1]) % 3
		found[res % 3] = last_found[0] + 1;
		found[(res+1) % 3] = last_found[1];
		found[(res+2) % 3] = last_found[2];
		sum_found += found[0]
		tmp = last_found
		last_found = found
		found = tmp
	return sum_found

n, m = map(int, raw_input().split())
st = raw_input()
list_st = list(st)
for t in range(m):
	qt, a, b = map(int, raw_input().split())
	if qt == 1:
		list_st[a-1] = str(b)
	else:
		print num_substring(list_st, a, b)
