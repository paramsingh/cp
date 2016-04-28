#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int a[100][100];
int sol;
int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

inline int valid(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= m);
}

int paths(int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];
    int cur = 0;
    int gexists = 0, sexists = 0;
    int ans = 0;
    for (int x = 0; x < 4; x++) {
        int ni = i + dx[x];
        int nj = j + dy[x];
        if (valid(ni, nj)) {
            if (a[i][j] > a[ni][nj]) {
                sexists = 1;
                ans += paths(ni, nj);
            }
            else if (a[i][j] < a[ni][nj]) {
                gexists = 1;
            }
        }
    }
    if (sexists == 0)
        ans = 1;
    if (gexists == 0)
        sol += ans;
    return dp[i][j] = ans;
}

int main(void) {
    int t, cs = 1;
    scanf("%d", &t);
    while (t--) {
        memset(dp, -1, sizeof(dp));
        sol = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                paths(i, j);
            }
        }
        printf("Case #%d: %d\n", cs++, sol);
    }
    return 0;
}

