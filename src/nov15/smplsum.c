// Author: Param Singh <paramsingh258@gmail.com>
// Simple Sum: https://www.codechef.com/NOV15/problems/SMPLSUM

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000001

void fastread(int *a) {
    char c = 0;
    while (c < 33)
        c = getchar_unlocked();
    *a = 0;
    while (c > 33) {
        *a = (*a) * 10 + c - '0';
        c = getchar_unlocked();
   }
}

int seive[MAX] = {0};
int prime[MAX];
int phi[MAX];
int p[25], mul[25], l;
long long int sum;

void factors(int c, int a) {
    if (c == l) {
        sum += ((long long)(a) * phi[a]);
        return;
    }
    int i;
    for (i = 0; i <= mul[c]; i++) {
        factors(c+1, a);
        a *= p[c];
    }
}

int main(void) {
    int count = 0;
    int i, j, k;
    seive[1] = 1;
    phi[1] = 1;
    for (i = 2; i < MAX; i++) {
        if (seive[i] == 0) {
            seive[i] = i;
            prime[count++] = i;
            phi[i] = i-1;
        }
        else {
            if (seive[i] == seive[i / seive[i]])
                phi[i] = phi[i / seive[i]] * seive[i];
            else
                phi[i] = phi[i / seive[i]] * (seive[i] - 1);
        }
        for (j = 0; j < count && prime[j] <= seive[i] && prime[j] * i < MAX; j++)
            seive[i * prime[j]] = prime[j];
    }

    int t;
    fastread(&t);
    while (t--) {
        int n;
        fastread(&n);
        l = 0;
        while (n > 1) {
            if (l != 0 && seive[n] == p[l-1])
                mul[l-1]++;
            else {
                p[l] = seive[n];
                mul[l++] = 1;
            }
            n /= seive[n];
        }
        sum = 0;
        factors(0, 1);
        printf("%lld\n", sum);
    }
    return 0;
}
