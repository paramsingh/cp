// Author: Param Singh <paramsingh258@gmail.com>
// EGRCAKE : http://www.codechef.com/NOV15/problems/EGRCAKE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

long long int gcd(long long int a, long long int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    int t;
    scanf("%d", &t);
    long long int k, n, m, h, p;
    while (t--) {
        scanf("%lld %lld", &n, &m);
        if (m == 0) {
            if (n != 1)
                printf("No 1\n");
            else
                printf("Yes\n");
        }
        else {
            h = gcd(n, m);
            p = m / h;
            k = (p * n) / m;
            if (k < n)
                printf("No %lld\n", k);
            else
                printf("Yes\n");
        }
    }
    return 0;
}
