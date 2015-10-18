t = int(raw_input())
for _ in range(t):
    n = int(raw_input())
    w = raw_input().split()
    x = w.pop(0)
    l = len(x)
    ans = ""
    for i in range(l):
        for j in range(i, l+1):
            common = True
            sub = x[i:j]
            for string in w:
                if sub not in string:
                    common = False
                    break
            if common:
                if len(sub) > len(ans) or (len(sub) == len(ans) and ans > sub):
                    ans = sub
    print ans
