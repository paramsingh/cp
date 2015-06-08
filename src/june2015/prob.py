def area_trap(side1, side2, normal):
    return 0.5 * (side1 + side2) * normal


def area_triangle(normal, base):
    return 0.5 * normal * base

cases = int(raw_input())
for term in range(cases):
    # flag1, flag2 = False, False

    timex, timey, waitx, waity = map(float, raw_input().split())

    # boundary rectangle whose area is net area
    rect = [(0.0, 0.0), (0.0, timey), (timex, timey), (timex, 0.0)]
    net = timex * timey

    lp1 = (0.0, waitx)             # point of left line on y axis
    lp2 = (timex, timex+waitx)   # point of left line on line x = timex

    rp1 = (waity, 0.0)            # point of right line on x axis
    rp2 = (timey+waity, timey)  # point of right line on line y = timey

    # point of left line on line y = timey
    lp3 = (lp2[0] * (timey - lp1[1]) / (lp2[1] - lp1[1]), timey)

    # point of right line on line x = timex
    rp3 = (timex, (rp2[1] - rp1[1]) / (rp2[0] - rp1[0]) * (timex - rp1[0]))

    # print "Left line: ", lp1, lp2, lp3
    # print "Right line: ", rp1, rp2, rp3

    if lp3[0] <= 0 and rp3[1] <= 0:
        # print "34"
        ans = 1.0
        print "%.6f" % ans
        continue
    elif lp3[0] <= 0:
        if rp3[1] >= timey:
            # print "39"
            x = area_trap(timex - rp2[0], timex - rp1[0], timey)  # corrected
            ans = 1.0 - (x / net)
            print "%.6f" % ans
            continue
        else:
            # print "44"
            x = area_triangle(rp3[1], timex - rp1[0])  # corrected
            ans = 1.0 - (x / net)
            print "%.6f" % ans
            continue
    elif rp3[1] <= 0:
        if lp3[0] >= timex:
            # print "50"
            x = area_trap(timey - lp2[1], timey - lp1[1], timex)  # correct
            ans = 1.0 - (x / net)
            print "%.6f" % ans
            continue
        else:
            # print "55"
            x = area_triangle(lp3[0], timey - lp1[1])  # correct
            ans = 1.0 - (x / net)
            print "%.6f" % ans
            continue
    else:
        if lp3[0] <= timex and rp3[1] <= timey:
            # print "61"
            x = area_triangle(timey - lp1[1], lp3[0]) + area_triangle(rp3[1], timex - rp1[0])  # correct
            ans = 1.0 - (x / net)
            print "%.6f" % ans
            continue
        elif lp3[0] <= timex:
            # print "72"
            x = area_triangle(timey-lp1[1], lp3[0]) + area_trap(timex - rp1[0], timex - rp2[0], timey)  # correct
            ans = 1.0 - (x / net)
            print "%.6f" % ans
            continue
        elif rp3[1] <= timey:
            # print "78"
            x = area_trap(timey - lp1[1], timey - lp2[1], timex) + area_triangle(rp3[1], timex - rp1[0])
            ans = 1.0 - (x / net)
            print "%.6f" % ans
            continue
        else:
            raise ArithmeticError  # no idea why, but yeah whatevs
