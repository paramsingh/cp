#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m, x, y;
char s[1010][1010];
int black[1010], white[1010];
int dp[3][1010][1010];

int solve(int here, int cons, int prev) {
    if (here == m) {
        if (cons < x || cons > y)
            return inf;
        else
            return 0;
    }
    if (dp[prev][here][cons] != -1)
        return dp[prev][here][cons];
    int rtob = white[here], rtow = black[here];
    int ans;
    if (prev == 0) { // white
        if (cons < x)
            ans = solve(here + 1, cons + 1, prev) + rtow;
        else if (cons >= x && cons < y) {
            ans = solve(here + 1, cons + 1, prev) + rtow;
            ans = min(ans, solve(here + 1, 1, prev ^ 1) + rtob);
        }
        else if (cons >= y)
            ans = solve(here + 1, 1, prev ^ 1) + rtob;
    }
    else {
        if (cons < x)
            ans = solve(here + 1, cons + 1, prev) + rtob;
        else if (cons >= x && cons < y) {
            ans = solve(here + 1, cons + 1, prev) + rtob;
            ans = min(ans, solve(here + 1, 1, prev ^ 1) + rtow);
        }
        else if (cons >= y)
            ans = solve(here + 1, 1, prev ^ 1) + rtow;
    }
    return dp[prev][here][cons] = ans;
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '#')
                black[j]++;
            else
                white[j]++;
        }
    }
    printf("%d\n", min(solve(0, 0, 0), solve(0, 0, 1)));
}
