#include <bits/stdc++.h>
typedef long long lli;

lli a[100100];
int done[100100];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    lli sum = 0;
    lli ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
        ans += a[i] * a[i-1];
        sum += a[i];
    }
    ans += a[n] * a[1];
    for (int i = 0; i < k; i++) {
        int id;
        scanf("%d", &id);
        int s = sum;
        int prev = id - 1 == 0 ? n : id - 1;
        int next = id + 1 == n + 1 ? 1 : id + 1;
        if (done[prev] == 0)
            s -= a[prev];
        if (done[next] == 0)
            s -= a[next];
        s -= a[id];
        ans += a[id] * s;
        done[id] = 1;
        sum -= a[id];
    }
    std::cout << ans << std::endl;
    return 0;
}

