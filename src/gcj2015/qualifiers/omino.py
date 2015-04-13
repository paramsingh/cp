terms = int(raw_input())
g = "GABRIEL"
r = "RICHARD"
values = [
    [[g,r,r,r], [g,g,r,r], [g,r,r,r], [g,g,r,r]],
    [[g,g,r,r], [g,g,r,r], [g,g,g,r], [g,g,r,r]],
    [[g,r,r,r], [g,g,g,r], [g,r,g,r], [g,g,g,g]],
    [[g,g,r,r], [g,g,r,r], [g,g,g,g], [g,g,r,g]],
]
for term in range(1, terms+1):
    x, l, y = map(int, raw_input().split())
    print "Case #%s: %s" % (term, values[l-1][y-1][x-1])
