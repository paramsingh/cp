# initial (probably really slow) code
# let's hope python's sorting algorithm is fast enough for codechef
# it's probably not :(

import sys
sysmin = - sys.maxint - 1

def create_rect(coords):
    coords = map(int, coords.split())
    maxx, maxy = sysmin, sysmin
    for i, x in enumerate(coords):
        if i % 2 == 0:
            if maxx < x:
                maxx = x
        else:
            if maxy < x:
                maxy = x

    return (maxx, maxy)


def is_inside(a, b):
    xa, ya = a
    xb, yb = b
    if xa <= xb and ya <= yb:
        return -1
    else:
        return 1


cases = int(raw_input())
for case in range(cases):
    polygons = int(raw_input())
    lst = []
    for x in range(polygons):
        raw_input()
        coords = raw_input()
        rep = create_rect(coords)
        lst.append(rep)

    dup = lst[:]
    lst = sorted(lst, cmp = is_inside)
    print ' '.join(map(lambda x: str(lst.index(x)), dup))
