#include <bits/stdc++.h>
#define SIZE 1000100

int phi[SIZE];

int main(void) {
    int i;
    phi[1] = 1;
    for (i = 2; i < SIZE; i++)
        phi[i] = i;
    for (i = 2; i < SIZE; i++) {
        if (phi[i] == i) {
            for (int j = i; j < SIZE; j+=i)
                phi[j] -= phi[j] / i;
        }
    }
    float max = -1;
    int ans = 0;
    for (i = 2; i <= 1000000; i++) {
        if (max < i / (float) phi[i]) {
            max = i / (float) phi[i];
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}

