# http://www.codechef.com/DEC14/problems/CAPPLE

def pluck(trees):

	# find the biggest and the second biggest number in the list
	maximum = max(trees)
	second_max = max( map(lambda x: -1 if x == maximum else x, trees) )

	if maximum == second_max:
		return [0]*len(trees)
	else:
		diff = maximum - second_max
		return map(lambda x: x - diff if x == maximum else x, trees)

def time(trees):
	counter = 0
	while not all(i == 0 for i in trees):
		trees = pluck(trees)
		counter += 1
	return counter - 1

'''print time(range(1,1000))'''
inputs = int(raw_input())
while inputs:
	length = int(raw_input())
	trees = map(int, raw_input().split())
	print time(trees)
	inputs -= 1