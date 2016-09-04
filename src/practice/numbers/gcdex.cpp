#include <bits/stdc++.h>
typedef long long lli;

int phi[1001000];
lli x[1001000];
lli ans[1001000];

int main(void) {
    for (int i = 0; i <= 1000000; i++)
        phi[i] = i;
    for (int i = 2; i <= 1000000; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= 1000000; j += i)
                phi[j] -= phi[j] / i;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i)
            x[j] += ((long long)i) * phi[j / i];
    }

    for (int i = 2; i <= 1000000; i++)
        ans[i] = ans[i - 1] + x[i] - i;

    int n;
    scanf("%d", &n);
    while (n != 0) {
        printf("%lld\n", ans[n]);
        scanf("%d", &n);
    }
    return 0;
}
