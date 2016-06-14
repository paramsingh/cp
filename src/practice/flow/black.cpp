#include <bits/stdc++.h>
using namespace std;


int reqtime[200][200];
int match[400];
int done[400];
vector<int> graph[200];
int n, m, c, k;

int findmatch(int u) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (done[v]) continue;
        done[v] = 1;
        if (match[v] == -1 || findmatch(match[v])) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int bpm() {
    memset(match, -1, sizeof(match));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(done, 0, sizeof(done));
        if (findmatch(i))
            cnt++;
    }
    return cnt;
}

int check(long long t) {
    for (int i = 1; i <= n; i++)
        graph[i].clear();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (reqtime[i][j] <= t)
                graph[i].push_back(j);
            if (reqtime[i][j] + c <= t)
                graph[i].push_back(j+m);
        }
    }
    int saved = bpm();
    return saved >= k;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &m, &k, &c);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &reqtime[i][j]);
            }
        }
        long long lo = 0, hi = 10000000000;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        printf("%lld\n", lo);
    }
    return 0;
}

