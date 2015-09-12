# Author: Param Singh <paramsingh258@gmail.com>
# Cracking the code

i, k, s = map(int, raw_input().split())
ai, bi = map(int, raw_input().split())
diff = k - i
v = diff / 2
if diff % 2 == 0:
    val = (2 ** (4*v-s)) * (ai + bi)
else:
    val = (2 ** (4*v - s + 1.5) * (ai + (3 ** 0.5) * bi))
print "%f" % val
