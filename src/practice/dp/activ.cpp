#include <bits/stdc++.h>
#define MOD 100000000
using namespace std;

int dp[100100];
pair<int, int> event[100100];

inline int check(int a, int b) {
    int sa = event[a].first, ea = event[a].second;
    int sb = event[b].first, eb = event[b].second;
    return (eb <= sa);
}

int ans(int n) {
    if (dp[n] != -1) return dp[n];

    if (n == 0)
        return 1;

    int dont = ans(n - 1);
    // find the one next event that can be taken
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (event[mid].first <= event[n].second) // can take
            lo = mid;
        else
            hi = mid - 1;
    }
    if (event[lo].first > event[n].second)
        return dp[n] = dont + 1;
    else
        return dp[n] = (dont + ans(lo) + 1) % MOD;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n != -1) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int s, e;
            scanf("%d %d", &s, &e);
            event[i] = make_pair(e, s);
        }
        sort(event, event + n);
/*        printf("after sorting\n");
        for (int i = 0; i < n; i++)
            printf("%d %d\n", event[i].second, event[i].first); */
        int sol = ans(n - 1);
        int dup = sol;
        int dig = 0;
        while (dup != 0) {
            dig++;
            dup /= 10;
        }
        while (dig < 8) {
            printf("0");
            dig++;
        }
        printf("%d\n", sol);
        scanf("%d", &n);
    }
    return 0;
}
