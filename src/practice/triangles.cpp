// http://codeforces.com/problemset/problem/229/C

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int ord[1000100] = {0};

int main(void) {
    int n, m;
    int u, v;
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        ord[u] += 1;
        ord[v] += 1;
    }
    lli t = (lli)(n) * (n-1) * (n-2) / 6;
    lli rem = 0;
    for (int i = 1; i <= n; i++)
        rem += ord[i] * ((lli)n - 1 - ord[i]);
    lli ans = t - rem / 2;
    cout << ans << endl;
    return 0;
}
