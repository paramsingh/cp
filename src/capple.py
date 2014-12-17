# http://www.codechef.com/DEC14/problems/CAPPLE

def pluck(trees):
	# check if all the elements in the list are the same
	different = False
	dummy = trees[0]
	for i in trees:
		if i != dummy:
			different = True
			break

	if not different:
		return [0]*len(trees)

	# find the biggest and the second biggest number in the list
	first, second = None, None
	for n in trees:
	    if n > first:
	        first, second = n, first
	    elif first > n > second:
	        second = n

	diff = first - second
	return map(lambda x: x - diff if x == first else x, trees)

def time(trees):
	counter = 0
	while not all(i == 0 for i in trees):
		trees = pluck(trees)
		counter += 1
	return counter

inputs = int(raw_input())
while inputs:
	length = int(raw_input())
	trees = map(int, raw_input().split())
	print time(trees)
	inputs -= 1