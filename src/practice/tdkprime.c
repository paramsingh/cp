// http://www.spoj.com/problems/TDKPRIME

#include <stdio.h>
#include <stdlib.h>
#define MAX 86044176
#define SQRT 9267
#define isp(n) (seive[n>>6]&(1<<((n>>1)&31)))
#define setp(n) (seive[n>>6]|=(1<<((n>>1)&31)))

int seive[MAX >> 6] = {0};
int primes[5000100];
int main(void) {
    int i, j, k;
    for (i = 3; i < SQRT; i+=2) {
        if (!isp(i)) {
            for (j = i*i, k = i << 1; j < MAX; j+=k) {
                setp(j);
            }
        }
    }
    int c = 2;
    primes[1] = 2;
    for (i = 3; i < MAX && c <= 5000000; i+=2) {
        if (!isp(i))
            primes[c++] = i;
    }
    int n, q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        printf("%d\n", primes[n]);
    }
    return 0;
}
