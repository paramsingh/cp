#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int f[10010];
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", f + i);
    sort(f + 1, f + m + 1);
    int ans = inf;
    for (int i = 1; i + n - 1 <= m; i++)
        ans = min(ans, f[i + n - 1] - f[i]);
    printf("%d\n", ans);
}
