#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int a[200100];

lli sc[200100];
lli sac[200100];
lli tc[200100];
lli tac[200100];
lli add[200100];
lli add1[200100];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            add[i] = add1[i] = 0;
        }
        int s, t;
        scanf("%d %d", &s, &t);
        s--, t--;
        int u = (s + 1) % n;
        lli cur = a[s];
        while (true) {
            sc[u] = cur;
            if (u == s)
                break;
            cur += a[u];
            u = (u + 1) % n;
        }

        u = (s - 1) % n;
        if (u < 0)
            u += n;
        cur = a[u];
        while (true) {
            sac[u] = cur;
            if (u == s)
                break;
            u = (u - 1) % n;
            if (u < 0)
                u += n;
            cur += a[u];
        }

        u = (t + 1) % n;
        cur = a[t];
        while (true) {
            tc[u] = cur;
            if (u == t)
                break;
            cur += a[u];
            u = (u + 1) % n;
        }

        u = (t - 1) % n;
        if (u < 0)
            u += n;
        cur = a[u];
        while (true) {
            tac[u] = cur;
            if (u == t)
                break;
            u = (u - 1) % n;
            if (u < 0)
                u += n;
            cur += a[u];
        }


        lli ans = LLONG_MAX;
        int flag = 0;
        ans = min(ans, sc[t]); // direct
        ans = min(ans, sac[t]); // direct
        ans = min(ans, sc[t] + tac[t]);
        ans = min(ans, sac[t] + tc[t]);


        add[t] = 0;
        u = (t - 1) % n;
        if (u < 0)
            u += n;

        while (u != s) {
            int nxt = (u + 1) % n;
            add[u] = min(add[nxt], tac[u] + tac[u]);
            u = (u - 1) % n;
            if (u < 0)
                u += n;
        }

        add1[t] = 0;
        u = (t + 1) % n;
        while (u != s) {
            int prev = (u - 1) % n;
            if (prev < 0)
                prev += n;
            add1[u] = min(add1[prev], tc[u] + tc[u]);
            u = (u + 1) % n;
        }

        u = (s + 1) % n;
        flag = 0;
        while (true) {
            if (u == s)
                break;
            if (u == t) {
                flag = 1;
                u = (u + 1) % n;
                continue;
            }
            if (flag == 0) {
                ans = min(ans, sc[u] + tc[u]);
                ans = min(ans, sc[u] + tc[u] + add[u]);
                ans = min(ans, sac[u] + tac[u]);
            }
            else {
                ans = min(ans, sac[u] + tac[u]);
                ans = min(ans, sac[u] + tac[u] + add1[u]);
                ans = min(ans, sc[u] + tc[u]);
            }
            u = (u + 1) % n;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

