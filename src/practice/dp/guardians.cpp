#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli dp[1000][8010];
int opt[1000][8010];
lli prefix[8010];
int crazy[8010];
int l, g;

lli cost(int i, int j) {
    return (prefix[j] - prefix[i - 1]) * (j - i + 1);
}


void fill(int g, int l1, int l2, int p1, int p2) {
    if (l1 > l2)
        return;

    int mid = (l1 + l2) / 2;
    dp[g][mid] = LLONG_MAX;
    opt[g][mid] = -1;
    for (int i = p1; i <= p2; i++) {
        if (i > mid)
            break;
        lli c;
        if (p1 == 0)
            c = cost(1, mid);
        else
            c = dp[g-1][i] + cost(i + 1, mid);
        if (c < dp[g][mid]) {
            dp[g][mid] = c;
            opt[g][mid] = i;
        }
    }

    fill(g, l1, mid - 1, p1, opt[g][mid]);
    fill(g, mid + 1, l2, opt[g][mid], p2);
}


int main(void) {
    scanf("%d %d", &l, &g);
    for (int i = 1; i <= l; i++) {
        scanf("%d", crazy + i);
        prefix[i] = prefix[i - 1] + crazy[i];
    }

    for (int i = 1; i <= l; i++)
        dp[1][i] = cost(1, i);

    for (int i = 2; i <= g; i++)
        fill(i, 1, l, 1, l);

    printf("%lld\n", dp[g][l]);
    return 0;
}

