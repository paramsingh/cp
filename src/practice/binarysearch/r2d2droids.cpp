#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int droids[7][100100];
int ans[7];
int n, m, k;
int dp[7][20][100100];

inline int query(int j, int l, int r) {
    int lg = log2(r - l + 1);
    return max(dp[j][lg][l], dp[j][lg][r - (1 << lg) + 1]);
}


inline int get(int l, int r) {
    int cnt = 0;
    for (int j = 1; j <= m; j++)
        cnt += query(j, l, r);
    return cnt;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            scanf("%d", &droids[j][i]);
    }
    memset(dp, -1, sizeof(dp));
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++)
            dp[j][0][i] = droids[j][i];
        for (int lg = 1; (1 << lg) <= n; lg++) {
            int len = 1 << lg;
            for (int i = 1; i + len - 1 <= n; i++)
                dp[j][lg][i] = max(dp[j][lg - 1][i], dp[j][lg - 1][i + (1 << (lg - 1))]);
        }
    }
    int len = 0;
    for (int i = 1; i <= n; i++) {
        int lo = 1, hi = i;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int possible = get(mid, i) <= k;
            if (possible)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (get(lo, i) <= k) {
            int nlen = i - lo + 1;
            if (nlen > len) {
                len = nlen;
                for (int j = 1; j <= m; j++)
                    ans[j] = query(j, lo, i);
            }
        }
    }
    for (int j = 1; j <= m; j++)
        printf("%d ", ans[j]);
    printf("\n");
}
