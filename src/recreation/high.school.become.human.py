from math import log

x, y = map(int, input().split())
if x == y:
    print('=')
elif x == 1 or y == 1:
    print('<' if x < y else '>')
elif log(y, x) > y / float(x):
    print('<')
elif log(y, x) < y / float(x):
    print('>')
else:
    print('=')
