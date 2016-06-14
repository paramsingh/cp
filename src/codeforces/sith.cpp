#include <bits/stdc++.h>
using namespace std;

double dp[20][300000];
int n;
double prob[20][20];

double ans(int x, int mask) {
    if (dp[x][mask] != -1)
        return dp[x][mask];
    if (x == 0) {
        double p = 1;
        for (int i = 1; i < n; i++) {
            if ((mask >> i) & 1)
                continue;
            else
                p = p * prob[x][i];
        }
        return dp[x][mask] = p;
    }
    else {
        double p = ans(0, mask) * prob[0][x];
        for (int i = 1; i < n; i++) {
            if ((mask >> i) & 1 || i == x)
                continue;
            else {
                double xwins = ans(x, mask | (1 << i)) * prob[x][i];
                double iwins = ans(i, mask | (1 << i)) * prob[i][x];
                p = max(p, xwins + iwins);
            }
        }
        return dp[x][mask] = p;
    }
}

int main(void) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 300000; j++)
            dp[i][j] = -1;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> prob[i][j];
        }
    }

    double p = ans(0, 0);
    for (int i = 1; i < n; i++) {
        p = max(p, ans(i, (1 << i)));
    }
    printf("%.15lf\n", p);
    return 0;
}


