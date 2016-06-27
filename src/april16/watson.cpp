#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int power(int a, int b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        int x = power(a, b/2);
        x = ((long long)x * x) % MOD;
        return x;
    }
    else {
        int x = power(a, (b-1)/2);
        x = ((long long)x * x) % MOD;
        x = ((long long)x * a) % MOD;
        return x;
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int ans = power(k-1, n-1);
        ans = (ans * (long long)k) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}
