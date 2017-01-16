#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

int cost[310][310];
int p[310];
int n, m;

int main(void) {
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            p[i] = 1;
            for (int j = 1; j <= m; j++)
                scanf("%d", &cost[i][j]);
            sort(cost[i] + 1, cost[i] + 1 + m);
        }
        ll ans = 0;
        for (int day = 1; day <= n; day++) {
            ll mn = inf, use = -1;
            for (int i = 1; i <= day; i++) {
                if (p[i] > m) continue;
                ll add = cost[i][p[i]] + 2 * p[i] - 1;
                if (mn > add) {
                    mn = add;
                    use = i;
                }
            }
            ans += mn;
            p[use]++;
        }
        printf("Case #%d: %lld\n", c, ans);
    }
}
