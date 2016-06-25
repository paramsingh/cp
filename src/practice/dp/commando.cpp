#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


vector<lli> m;
vector<lli> c;

inline int bad(lli m1, lli c1, lli m2, lli c2, lli m3, lli c3) {
    return (m2 - m1) * (c1 - c3) < (c1 - c2) * (m3 - m1);
}

void add(lli m3, lli c3) {
    while (m.size() >= 2) {
        int s = m.size() - 1;
        if (bad(m[s - 1], c[s - 1], m[s], c[s], m3, c3)) {
            m.pop_back();
            c.pop_back();
        }
        else break;
    }
    m.push_back(m3);
    c.push_back(c3);
}

int cur = 0;

lli query(lli x) {
    if (cur >= m.size())
        cur = m.size() - 1;

    while (cur < m.size() - 1 && m[cur] * x + c[cur] < m[cur + 1] * x + c[cur + 1])
        cur++;
    return m[cur] * x + c[cur];
}

int x[1000100];
lli sum[1000100];
lli dp[1000100];

int main(void) {
    int t, n, a, b, cx;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%d %d %d", &a, &b, &cx);
        sum[0] = dp[0] = 0;
        for (int i = 1; i <= n; i++) {
           scanf("%d", x+i);
           sum[i] = sum[i-1] + x[i];
        }
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                dp[i] = query(sum[i]) + (a * sum[i] * sum[i]) + (b * sum[i]) + cx;
                dp[i] = max(a * sum[i] * sum[i] + b * sum[i] + cx, dp[i]);
            }
            else
                dp[1] = (a * sum[1] * sum[1]) + (b * sum[1]) + cx;
            add(-2 * a * sum[i], dp[i] + (a * sum[i] * sum[i]) - (b * sum[i]));
        }
        printf("%lld\n", dp[n]);
        m.clear();
        c.clear();
        cur = 0;
    }
    return 0;
}
