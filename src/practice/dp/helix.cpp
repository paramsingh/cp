#include <bits/stdc++.h>
using namespace std;

int dp[10100][3];
int a[3][10100];
int size[3];


int ans(int l, int id) {
    if (dp[l][id] != -1)
        return dp[l][id];
    if (l > size[id])
        return 0;
    else {
        int x = a[id][l];
        int lo = 1, hi = size[id^1];
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (a[id^1][mid] >= x)
                hi = mid;
            else
                lo = mid + 1;
        }
        int sol = INT_MIN;
        if (a[id^1][lo] == x) {
            sol = x + ans(lo+1, id^1);
        }
        sol = max(sol, x + ans(l+1, id));
        return dp[l][id] = sol;
    }
}

int main(void) {
    while (true) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", size);
        if (size[0] == 0)
            break;
        for (int i = 1; i <= size[0]; i++)
            scanf("%d", &a[0][i]);
        scanf("%d", &size[1]);
        for (int i = 1; i <= size[1]; i++)
            scanf("%d", &a[1][i]);
        printf("%d\n", max(ans(1, 0), ans(1, 1)));
    }
    return 0;
}
