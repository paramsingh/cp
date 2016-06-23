#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;

struct two {
    int x, y;
};

inline int scanint() {
    register int x = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar_unlocked();
    }
    return x;
}

int a[1001][1001];
lli s[1001][1001];
lli ans[1001][1001];
two dp[11][11][1001][1001];

inline lli qsum(int x1, int y1, int x2, int y2) {
    lli sum = s[x2][y2];
    if (x1 > 0)
        sum -= s[x1 - 1][y2];
    if (y1 > 0)
        sum -= s[x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        sum += s[x1 - 1][y1 - 1];
    return sum;
}

int k2, k1;
inline int qmax(int x1, int y1, int x2, int y2) {
    int ans = INT_MIN;
    int lux = dp[k1][k2][x1][y1].x;
    int luy = dp[k1][k2][x1][y1].y;
    ans = a[lux][luy];
    int rux = dp[k1][k2][x1][y2 - (1 << k2) + 1].x;
    int ruy = dp[k1][k2][x1][y2 - (1 << k2) + 1].y;
    ans = max(ans, a[rux][ruy]);
    int ldx = dp[k1][k2][x2 - (1 << k1) + 1][y1].x;
    int ldy = dp[k1][k2][x2 - (1 << k1) + 1][y1].y;
    ans = max(ans, a[ldx][ldy]);
    int rdx = dp[k1][k2][x2 - (1 << k1) + 1][y2 - (1 << k2) + 1].x;
    int rdy = dp[k1][k2][x2 - (1 << k1) + 1][y2 - (1 << k2) + 1].y;
    ans = max(ans, a[rdx][rdy]);
    return ans;
}

int main(void) {
    int n, m;
    n = scanint();
    m = scanint();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = scanint();
            ans[i+1][j+1] = -1;
        }
    }

    s[0][0] = a[0][0];
    for (int i = 1; i < m; i++)
        s[0][i] = a[0][i] + s[0][i-1];

    for (int i = 1; i < n; i++) {
        s[i][0] = a[i][0] + s[i-1][0];
        lli pref = a[i][0];
        for (int j = 1; j < m; j++) {
            s[i][j] = a[i][j] + s[i-1][j] + pref;
            pref += a[i][j];
        }
    }

    // base cases for rmq
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt++;
            dp[0][0][i][j].x = i;
            dp[0][0][i][j].y = j;
        }
    }

    // now for j = 0;
    int li = log2(n);
    int lj = log2(m);
    for (int i = 1; i <= li; i++) {
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n - (1 << i) + 1; x++) {
                int ux  = dp[i - 1][0][x][y].x;
                int uy  = dp[i - 1][0][x][y].y;
                int dx = dp[i-1][0][x + (1 << (i - 1))][y].x;
                int dy = dp[i-1][0][x + (1 << (i - 1))][y].y;
                if (a[ux][uy] > a[dx][dy]) {
                    dp[i][0][x][y].x = ux;
                    dp[i][0][x][y].y = uy;
                }
                else {
                    dp[i][0][x][y].x = dx;
                    dp[i][0][x][y].y = dy;
                }
            }
        }
    }

    // now for all j
    for (int j = 1; j <= lj; j++) {
        for (int i = 0; i <= li; i++) {
            for (int x = 0; x + (1 << i) -1 < n; x++) {
                for (int y = 0; y + (1 << j) - 1 < m; y++) {
                    cnt++;
                    int lx = dp[i][j-1][x][y].x;
                    int ly = dp[i][j-1][x][y].y;
                    int rx = dp[i][j-1][x][y + (1 << (j - 1))].x;
                    int ry = dp[i][j-1][x][y + (1 << (j - 1))].y;
                    if (a[rx][ry] > a[lx][ly]) {
                        dp[i][j][x][y].x = rx;
                        dp[i][j][x][y].y = ry;
                    }
                    else {
                        dp[i][j][x][y].x = lx;
                        dp[i][j][x][y].y = ly;
                    }
                }
            }
        }
    }

    int q;
    q = scanint();
    while (q--) {
        int a, b;
        a = scanint();
        b = scanint();
        if (ans[a][b] != -1) {
            printf("%lld\n", ans[a][b]);
            continue;
        }
        long long int sol = LLONG_MAX;
        k2 = log2(b);
        k1 = log2(a);
        int mxx = n - a + 1;
        int mxy = m - b + 1;
        for (int x = 0; x < mxx; x++) {
            for (int y = 0; y < mxy; y++) {
                lli s = qsum(x, y, x + a - 1, y + b - 1);
                lli m = qmax(x, y, x + a - 1, y + b - 1);
                sol = min(sol, (m * a * b) - s);
            }
        }
        ans[a][b] = sol;
        printf("%lld\n", ans[a][b]);
    }

    return 0;
}
