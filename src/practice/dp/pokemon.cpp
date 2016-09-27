#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p, a, d, q;
double dp[60][30];
ll choose[30][30];


ll c(int n, int r) {
    if (n < r)
        return 0;
    return choose[n][r];
}

double solve(int day = 0, int met = 0) {
    if (day == d) {
        if (met == q)
            return 1.0;
        else
            return 0.0;
    }
    if (dp[day][met] != -1)
        return dp[day][met];
    double ans = 0;
    for (int i = 0; i <= a; i++) {
        ans += (c(p - met, i) * c(met, a - i) * solve(day + 1, met + i)) / c(p, a);
    }
    return dp[day][met] = ans;
}

int main(void) {

    for (int i = 0; i < 30; i++)
        choose[i][0] = 1, choose[i][1] = i;

    for (int i = 1; i < 30; i++) {
        for (int j = 2; j <= i; j++) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
        }
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 60; i++)
            for (int j = 0; j < 30; j++)
                dp[i][j] = -1;
        scanf("%d %d %d %d", &p, &a, &d, &q);
        printf("%.15lf\n", solve());
    }
}
