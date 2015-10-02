# Author: Param Singh <paramsingh258@gmail.com>
# Time Measure: https://www.codechef.com/OCT15/problems/TIMEASR
from math import floor
t = int(raw_input())
for _ in range(t):
    a = float(raw_input())
    for x in range(12):
        y1 = 2.0 * (30*x - a) / 11.0
        y2 = 2.0 * (30*x + a) / 11.0
        y3 = 2.0 * (30*x - 360 + a) / 11.0
        y4 = 2.0 * (30*x + 360 - a) / 11.0
        fy1 = round(y1)
        fy2 = round(y2)
        fy3 = round(y3)
        fy4 = round(y4)
        a1 = (30*x - 5.5*fy1)
        a2 = -(30*x - 5.5*fy2)
        a3 = 360 - (30*x - 5.5*fy3)
        a4 = 360 + (30*x - 5.5*fy4)
        eps = 1 / 120.0
        if abs(a-a1) <= eps and 0 <= fy1 < 60:
            print "%02d:%02d" % (x, fy1)
            if a1 == 0 or a1 == 180:
                continue
        if abs(a-a2) <= eps and 0 <= fy2 < 60:
            print "%02d:%02d" % (x, fy2)
            if a2 == 0 or a2 == 180:
                continue
        if abs(a-a3) <= eps and 0 <= fy3 < 60:
            print "%02d:%02d" % (x, fy3)
        if abs(a - a4) <= eps and 0 <= fy4 < 60:
            print "%02d:%02d" % (x, fy4)
