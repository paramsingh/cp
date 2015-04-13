terms = int(raw_input())
for case in range(1,terms+1):
    inp = raw_input().split()
    smax = int(inp[0])
    s = map(int, list(inp[1]))
    people_standing = 0
    ans = 0
    for index, n in enumerate(s):
        if people_standing >= index:
            people_standing += n
        else:
            people_added = index - people_standing
            ans += people_added
            people_standing += people_added
            people_standing += n
    print "Case #%s: %s" % (case, ans)
