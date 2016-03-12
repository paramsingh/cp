#include <bits/stdc++.h>
int v[10];

int dp[100100][20];
int k;

int can(int req, int i) {
    if (dp[req][i] != -1)
        return dp[req][i];
    if (req == 0)
        return dp[req][i] = 1;
    if (i == 0)
        return dp[req][i] = (req % v[i] == 0);
    else {
        int use = 0;
        while (req >= use * v[i]) {
            if (can(req - use * v[i], i - 1))
                return dp[req][i] = 1;
            use++;
        }
        return dp[req][i] = 0;
    }
}

int main(void) {
    for (int i = 0; i < 100100; i++)
        for (int j = 0; j < 20; j++)
            dp[i][j] = -1;
    int x;
    scanf("%d", &x);
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
        scanf("%d", v+i);
    for (int i = 1; i < k; i++)
        v[i] = v[i] + v[i-1];
    if (can(x, k-1))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
