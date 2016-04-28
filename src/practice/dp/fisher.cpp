#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> graph[200];
vector<pii> risk[200];
int n, t;

int ris[200][300];
int tim[200][300];

pii ans(int u, int rem) {
    if (ris[u][rem] != -1)
        return make_pair(ris[u][rem], tim[u][rem]);
    if (u == 1 && rem >= 0) {
        return make_pair(0, 0);
    }
    if (rem < 0)
        return make_pair(1e9, rem);
    int mnr = 1e9, ti = -1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        if (v == u) continue;
        assert(risk[u][i].first == v);
        int wt = graph[u][i].second;
        int r = risk[u][i].second;
        pii go = ans(v, rem - wt);
        if (go.first + r < mnr) {
            mnr = go.first + r;
            ti = go.second + wt;
        }
    }
    ris[u][rem] = mnr;
    tim[u][rem] = ti;
    return make_pair(mnr, ti);
}

int main(void) {
    int test;
    while (true) {
        scanf("%d %d", &n, &t);
        if (n == 0 && t == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int w;
                scanf("%d", &w);
                graph[j].push_back(make_pair(i, w));
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int r;
                scanf("%d", &r);
                risk[j].push_back(make_pair(i, r));
            }
        }
        memset(ris, -1, sizeof(ris));
        memset(tim, -1, sizeof(tim));
        pii x = ans(n, t);
        if (x.first == 1e9)
            printf("-1\n");
        else
            printf("%d %d\n", x.first, x.second);
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            risk[i].clear();
        }
    }
    return 0;
}
