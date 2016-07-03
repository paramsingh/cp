import operator
fact = reduce(operator.mul, [x for x in range(1, 101)])
print reduce(operator.add, map(lambda x: ord(x) - ord('0'), str(fact)))
