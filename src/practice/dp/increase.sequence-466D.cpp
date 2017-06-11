#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int a[2010];
int dp[2010][2010];


int main(void) {
    int n, h;
    scanf("%d %d", &n, &h);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    // fill up the base cases
    dp[1][0] = (a[1] == h || a[1]  + 1 == h) ? 1 : 0; // left alone OR opened and closed
    dp[1][1] = (a[1] + 1 == h) ? 1 : 0; // opened and did not close

    for (int i = 2; i <= n; i++) {
        // the value of open must satisfy one of the following equations
        // a[i] + open = h     => open = h - a[i];
        // a[i] + open + 1 = h => open = h - a[i] - 1;
        for (int open = max(h - a[i] - 1, 0); open <= min(h - a[i], i); open++) {
            if (a[i] + open == h) {
                // do nothing
                dp[i][open] = (dp[i][open] + dp[i - 1][open]) % mod;

                // close one
                if (open > 0)
                    dp[i][open] = (dp[i][open] + dp[i - 1][open - 1]) % mod;

            }
            else if (a[i] + open + 1 == h) {
                // open one here and close it as well
                dp[i][open] = (dp[i][open] + dp[i - 1][open]) % mod;

                // have open + 1 from earlier and close one of them
                dp[i][open] = (dp[i][open] + (dp[i - 1][open + 1] * (ll)(open + 1)) % mod) % mod;

                // have open from earlier, close one of them and open your own
                dp[i][open] = (dp[i][open] + (dp[i - 1][open] * (ll)open) % mod) % mod;
            }
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}
