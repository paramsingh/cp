#include <bits/stdc++.h>
using namespace std;

int dp[1001];
vector<pair<int, int> > p;
int a[1010];
int b[1010];

int ans(int i) {
    if (dp[i] != -1)
        return dp[i];

    if (i == 0)
        return 1;
    int mx = 1;
    for (int j = i-1; j >= 0; j--) {
        if (p[j].second <= p[i].second) {
            mx = max(mx, ans(j) + 1);
        }
    }
    return dp[i] = mx;
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        p.clear();
        memset(dp, -1, sizeof(dp));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        for (int i = 1; i <= n; i++)
            scanf("%d", b+i);
        for (int i = 1; i <= n; i++)
            p.push_back(make_pair(a[i], b[i]));
        sort(p.begin(), p.end());
        int sol = 0;
        for (int i = 0; i < n; i++)
            sol = max(sol, ans(i));
        printf("%d\n", sol);
    }
    return 0;
}
