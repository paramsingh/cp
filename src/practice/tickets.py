import re
terms = int(raw_input())
for cases in range(terms):
    string = raw_input()
    x = string[0:2]
    if x[0] == x[1]:
        print "NO"
        continue
    regex = x.join(['(', ')*'])
    regex = re.compile(regex)
    l = len(string)
    begin, end = regex.match(string).span()
    if end == l - 1 and string[-1] == string[0]:
        print "YES"
        continue
    elif end == l:
        print "YES"
        continue
    else:
        print "NO"
