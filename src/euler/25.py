a = 1
b = 1
count = 2
while a < 10**999:
    a, b = b, a + b
    count += 1
print a
print count-1
