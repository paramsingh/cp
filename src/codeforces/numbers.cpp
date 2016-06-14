#include <bits/stdc++.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n < k)
        printf("%d\n", k);
    else {
        int div = n / k;
        printf("%lld\n", (div + 1) * (long long) k);
    }
    return 0;
}
