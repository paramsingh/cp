# http://www.codechef.com/DEC14/problems/XORSUB
import operator
def f(p):
	if p == []:
		return 0
	elif len(p) == 1:
		return p[0]
	else:
		return reduce(operator.xor, p)

def list_powerset(lst):
    result = [[]]
    for x in lst:
        result.extend([subset + [x] for subset in result])
    return result

t = int(raw_input())
while t:
	k = int(raw_input().split()[1])
	array = map(int, raw_input().split())
	max  = -1
	for i in list_powerset(array):
		if max < (k ^ f(i)):
			max = k ^ f(i)

	print max
	t -= 1