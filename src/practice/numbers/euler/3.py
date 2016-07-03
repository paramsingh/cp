primes = set()
seive = [0 for _ in range(5* 10**6)]
val = 600851475143
mx = 1
for i in range(2, 5* 10**6):
    if seive[i] == 0:
        j = i
        primes.add(i)
        if val % i == 0 and val > mx:
            mx = i
            val /= i
        while j < 5* 10**6:
            seive[j] = 1;
            j += i

print mx
