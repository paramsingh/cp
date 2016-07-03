#include <bits/stdc++.h>
#define SIZE 10000020

int phi[SIZE];

int check(int a, int b) {
    int af[10] = {0};
    int bf[10] = {0};
    while (a != 0) {
        af[a % 10]++;
        a /= 10;
    }
    while (b != 0) {
        bf[b % 10]++;
        b /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (af[i] != bf[i])
            return 0;
    }
    return 1;
}

int main(void) {
    int i;
    phi[1] = 1;
    for (i = 2; i < SIZE; i++)
        phi[i] = i;
    for (i = 2; i < SIZE; i++) {
        if (phi[i] == i) {
            for (int j = i; j < SIZE; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    int ans = 0;
    float min = 10000000;
    for (i = 2; i < 10000000; i++) {
        if (min > i / (float) phi[i] && check(i, phi[i])) {
            min = i / (float) phi[i];
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
