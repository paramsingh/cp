#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
int n;
struct rect {
    int h, w;
};

bool operator<(const rect& a, const rect& b) {
    if (a.h == b.h)
        return a.w < b.w;
    return a.h < b.h;
}


rect rects[50010];
rect r[50010];
lli dp[50010];
// lower envelope structure
// stacks for m and c in y = mx + c
vector<lli> m;
vector<lli> c;

inline int bad(lli m1, lli c1, lli m2, lli c2, lli m3, lli c3) {
    return ((m2 - m1) * (c1 - c3)) < ((c1 - c2) * (m3 - m1));
}

void add(lli m3, lli c3) {
    while (m.size() >= 2) {
        int s = m.size();
        lli m1 = m[s - 2];
        lli c1 = c[s - 2];
        lli m2 = m[s - 1];
        lli c2 = c[s - 1];
        if (bad(m1, c1, m2, c2, m3, c3)) {
            m.pop_back();
            c.pop_back();
        }
        else
            break;
    }
    m.push_back(m3);
    c.push_back(c3);
}

int cur = 0;
long long query(long long x) {
    if (cur >= m.size())
        cur = m.size() - 1;
    while (cur < m.size() - 1 && (m[cur] * x + c[cur]) > (m[cur + 1] * x + c[cur + 1])) {
        cur++;
    }
    return m[cur] * x + c[cur];
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &rects[i].h, &rects[i].w);
    sort(rects + 1, rects + 1 + n);

    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        while (cnt > 1 && r[cnt - 1].w <= rects[i].w)
            cnt--;
        r[cnt].h = rects[i].h;
        r[cnt].w = rects[i].w;
        cnt++;
    }

    add(r[1].w, 0);
    for (int i = 1; i < cnt; i++) {
        dp[i] = query(r[i].h);
        if (i != cnt - 1)
            add(r[i+1].w, dp[i]);
    }
    printf("%lld\n", dp[cnt - 1]);
    return 0;
}
