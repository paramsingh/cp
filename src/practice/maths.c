#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000100

int phi[SIZE];
long long int sums[SIZE];

void term(int n, int p) {
    if (p == 1) {
        printf("0/1 ");
        return;
    }

    if (p == 2) {
        printf("1/%d ", n);
        return;
    }

    if (p == sums[n]) {
        printf("1/1 ");
        return;
    }

    int a = 0, b = 1, c = 1, d = n, k, tc, td;
    int flag = 0;
    if (p > (sums[n] + 1) >> 2) {
        p = sums[n] + 1 - p;
        flag = 1;
    }
    int i;
    for (i = 3; i <= p; i++) {
        k = (int)((n + b) / d);
        tc = c;
        td = d;
        c = k*c - a;
        d = k*d - b;
        a = tc;
        b = td;
    }
    if (flag == 1)
        printf("%d/%d ", d-c, d);
    else
        printf("%d/%d ", c, d);
}

int main(void) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        phi[i] = i;
    }
    phi[1] = 1;
    for (i = 2; i < SIZE; i++) {
        if (phi[i] == i) {
            for (j = i; j < SIZE; j+=i)
                phi[j] -= phi[j] / i;
        }
    }
    sums[1] = 2;
    for (i = 2; i < SIZE; i++)
        sums[i] = phi[i] + sums[i-1];
    int n, p;
    while (1) {
        scanf("%d %d", &n, &p);
        if (n == 0 && p == 0)
            break;
        term(n, p);
        printf("%lld\n", sums[n]);
    }
    return 0;
}
