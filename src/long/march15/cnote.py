# http://www.codechef.com/MARCH15/problems/CNOTE

for terms in range(int(raw_input())):
    x, y, k, n = map(int, raw_input().split())
    req_pages = x - y
    flag = False
    for i in range(n):
        pi, ci = map(int, raw_input().split())
        if pi >= req_pages and ci <= k:
            flag = True
    if flag:
        print "LuckyChef"
    else:
        print "UnluckyChef"
