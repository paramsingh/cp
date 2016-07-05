#include <bits/stdc++.h>
using namespace std;
const int lim = 100000000 + 5;

int sieve[lim >> 6];
int pi[lim];

int main(void) {
    for (int i = 3; i <= sqrt(lim); i+=2) {
        if (sieve[i >> 6] & (1 << ((i >> 1) & 31)))
            continue;
        else {
            int k = i << 1;
            for (int j = i * i; j <= lim; j += k)
                sieve[j >> 6] |= (1 << ((j >> 1) & 31));
        }
    }
    pi[2] = 1;
    for (int i = 3; i <= lim; i++) {
        int c = 1;
        if (i % 2 == 0 || (sieve[i >> 6] & (1 << ((i >> 1) & 31))))
            c = 0;
        pi[i] = pi[i - 1] + c;
    }

    int x;
    scanf("%d", &x);
    while (x != 0) {
        double l = x / log(x);
        printf("%.1lf\n", fabs(pi[x] - l) * 100.0 / pi[x]);
        scanf("%d", &x);
    }
    return 0;
}
