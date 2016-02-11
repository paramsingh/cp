// http://codeforces.com/problemset/problem/22/C

#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;


int main(void) {
    int n, m, cut;
    scanf("%d %d %d", &n, &m, &cut);
    long long int mx = n - 1 + ((long long)(n-2) * (n-3)) / 2;
    if (m < n - 1 || m > mx) {
        printf("-1\n");
        return 0;
    }
    vector<pii> edges;
    int count = 0;
    int mid = 2;
    int u, v;
    for (int i = 1; i <= n; i++) {
        if (i == mid)
            continue;
        u = cut;
        v = i == cut ? mid : i;
        printf("%d %d\n", u, v);
        count++;
    }
    if (count == m)
        return 0;
    for (int i = 3; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            u = i == 2 ? cut : i == cut ? 2 : i;
            v = j == 2 ? cut : j == cut ? 2 : j;
            printf("%d %d\n", u, v);
            count++;
            if (count == m)
                return 0;
        }
    }
    return 0;
}
