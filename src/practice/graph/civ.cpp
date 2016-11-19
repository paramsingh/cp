#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int rad[300100];
int dia[300100];
int p[300100];
vector<int> graph[300100];

int find(int u) {
    return (p[u] == u) ? u : (p[u] = find(p[u]));
}

void merge(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    dia[pu] = max(dia[pu], max(dia[pv], rad[pu] + rad[pv] + 1));
    rad[pu] = (dia[pu] + 1) / 2;
    p[pv] = pu;
}

void join(int u, int v) {
    p[find(u)] = find(v);
}

int dp[300100];
int visited[300100];

pii dfs(int u, int p) {
    visited[u] = 1;
    dp[u] = 0;
    int au = u;
    for (auto v: graph[u]) {
        if (v == p) continue;
        pii x = dfs(v, u);
        if (x.second + 1 > dp[u]) {
            dp[u] = x.second + 1;
            au = x.first;
        }
    }
    return make_pair(au, dp[u]);
}


int main(void) {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        join(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            int start = dfs(i, -1).first;
            int pv = find(i);
            dia[pv] = dfs(start, -1).second;
            rad[pv] = (dia[pv] + 1) / 2;
        }
    }
    while (q--) {
        int type, x, y;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            int px = find(x);
            printf("%d\n", dia[px]);
        }
        else {
            scanf("%d %d", &x, &y);
            merge(x, y);
        }
    }
    return 0;
}
