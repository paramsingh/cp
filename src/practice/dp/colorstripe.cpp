#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

char s[500100];
int dp[30][500100];
int best[30][500100];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);

    // base cases
    for (int prev = 0; prev < k; prev++) {
        if (prev == s[n - 1] - 'A') {
            best[prev][n-1] = (s[n - 1] - 'A' + 1) % k;
            dp[prev][n-1] = 1;
        }
        else {
            best[prev][n - 1] = s[n - 1] - 'A';
            dp[prev][n - 1] = 0;
        }
    }

    // construct all dp states
    for (int i = n - 2; i >= 0; i--) {
        for (int prev = 0; prev < k; prev++) {
            dp[prev][i] = inf;
            for (int use = 0; use < k; use++) {
                if (use == prev) continue;
                int changes = dp[use][i + 1];
                if (use != s[i] - 'A')
                    changes++;
                if (dp[prev][i] > changes) {
                    dp[prev][i] = changes;
                    best[prev][i] = use;
                }
            }
        }
    }

    // find the answer
    int ans = inf, start;
    for (int prev = 0; prev < k; prev++) {
        if (dp[prev][0] < ans) {
            ans = dp[prev][0];
            start = prev;
        }
    }
    printf("%d\n", ans);

    // construct the answer string
    int cnt = 1, what = best[start][0];
    while (cnt <= n) {
        printf("%c", what + 'A');
        what = best[what][cnt++];
    }
    printf("\n");
    return 0;
}
