// 22:59
#include <bits/stdc++.h>
#define SIZE 200
#define INF 1000000000
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
const ll infll = 1e18;

vector<int> first[51];
vector<int> second[51];
int x[51];
int gold[51][26];
int bag[51];
vector<int> graph[51];
int m, n;
int done[51], match[51];

int findmatch(int u) {
    for (auto vault: graph[u]) {
        if (done[vault]) continue;
        done[vault] = 1;
        if (match[vault] == -1 || findmatch(match[vault])) {
            match[vault] = u;
            return 1;
        }
    }
    return 0;
}

inline int scan() {
    register int x = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar_unlocked();
    }
    return x;
}

int main(void) {
    int t;
    t = scan();
    while (t--) {
        m = scan(), n = scan();
        for (int i = 1; i <= m; i++)
            bag[i] = scan();
        sort(bag + 1, bag + m + 1);
        for (int i = 1; i <= n; i++) {
            x[i] = scan();
            for (int j = 0; j < x[i]; j++)
                gold[i][j] = scan();
            int fs = x[i] / 2, ss = x[i] - fs;
            for (int mask = 0; mask < (1 << fs); mask++) {
                int s = 0;
                for (int j = 0; j < fs; j++)
                    if (mask & (1 << j))
                        s += gold[i][j];
                first[i].push_back(s);
            }
            if (first[i].empty())
                first[i].push_back(0);
            sort(first[i].begin(), first[i].end());
            for (int mask = 0; mask < (1 << ss); mask++) {
                int s = 0;
                for (int j = 0; j < ss; j++) {
                    if (mask & (1 << j)) {
                        s += gold[i][j + fs];
                    }
                }
                second[i].push_back(s);

            }
            if (second[i].empty())
                second[i].push_back(0);
            sort(second[i].begin(), second[i].end());
        }
        for (int robber = 1; robber <= m; robber++) {
            // need to check for each vault if robber can rob this vault
            for (int vault = 1; vault <= n; vault++) {
                int flag = 0;
                for (int i = 0; i < first[vault].size(); i++) {
                    ll req = bag[robber] - first[vault][i];
                    int lo = 0, hi = second[vault].size() - 1;
                    while (lo < hi) {
                        int mid = (lo + hi) >> 1;
                        if (second[vault][mid] < req)
                            lo = mid + 1;
                        else
                            hi = mid;
                    }
                    if (second[vault][lo] == req) {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    graph[robber].push_back(vault);
            }
        }
        int ans = 0;
        memset(match, -1, sizeof(match));
        for (int i = m; i >= 1; i--) {
            memset(done, 0, sizeof(done));
            if (findmatch(i))
                ans += bag[i];
        }
        printf("%d\n", ans);
        for (int i = 1; i <= m; i++)
            graph[i].clear();
        for (int i = 1; i <= n; i++) {
            first[i].clear();
            second[i].clear();
        }
    }
    return 0;
}

