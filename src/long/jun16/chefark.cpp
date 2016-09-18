#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int fact[100100];
int fpow(int n, int a) {
    if (n == 1)
        return 1;
    if (a == 0)
        return 1;
    if (a == 1)
        return n;
    int half = fpow(n, a/2);
    if (a % 2 == 0) {
        return (half * (long long) half) % MOD;
    }
    else {
        int x = (half * (long long) half) % MOD;
        x = (x * (long long) n) % MOD;
        return x;
    }
}

inline int inv(int n) {
    return fpow(n, MOD - 2);
}

int choose(int n, int r) {
    if (n < r)
        return 0;
    int x = fact[n];
    x = (x * (long long) inv(fact[r])) % MOD;
    x = (x * (long long) inv(fact[n-r])) % MOD;
    return x;
}

int a[100100];
int main(void) {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 100001; i++)
        fact[i] = (fact[i-1] * (long long)i) % MOD;
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int flag = 0;
        int chg = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
            if (a[i] == 0)
                flag = 1;
            else
                chg++;
        }

        long long ans = 0;
        for (int i = 0; i <= min(k, chg); i++) {
            if (i % 2 == 0) {
                if (flag || k % 2 == 0)
                    ans = (ans + choose(chg, i)) % MOD;
            }
            else {
                if (flag || k % 2 != 0)
                    ans = (ans + choose(chg, i)) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
