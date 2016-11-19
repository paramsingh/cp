#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int a[100100];
int dp[100100];
int d[100100];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (x == 1) {
            dp[x] = 1;
            continue;
        }
        for (int j = 1; j * j <= x; j++) {
            d[1] = 0;
            if (x % j == 0) {
                int f1 = j, f2 = x / j;
                dp[x] = max(dp[x], d[f1] + 1);
                dp[x] = max(dp[x], d[f2] + 1);
            }
        }
        for (int j = 1; j * j <= x; j++) {
            d[1] = 0;
            if (x % j == 0) {
                int f1 = j, f2 = x / j;
                d[f1] = max(dp[x], d[f1]);
                d[f2] = max(dp[x], d[f2]);
            }
        }
    }
    int ans = -inf;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[a[i]]);
    printf("%d\n", ans);
    return 0;
}
