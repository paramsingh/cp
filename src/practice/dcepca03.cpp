#include <bits/stdc++.h>
#define SIZE 10040

int phi[SIZE];
int sums[SIZE];

int main(void) {
    int i;
    for (i = 0; i < SIZE; i++)
        phi[i] = i;
    for (i = 2; i < SIZE; i++) {
        if (phi[i] == i) {
            for (int j = i; j < SIZE; j+=i)
                phi[j] -= phi[j] / i;
        }
    }
    sums[1] = phi[1] = 1;
    for (i = 2; i < SIZE; i++)
        sums[i] = phi[i] + sums[i-1];
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long int ans = (long long) (sums[n]) * sums[n];
        printf("%lld\n", ans);
    }
    return 0;
}
