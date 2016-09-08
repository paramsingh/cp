#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
vector<pii> edges;
vector<pii> graph[200100];
vector<int> tree[200100];
int bridge[200100];
vector<int> bridges;
int low[200100], disc[200100];
int visited[200100];
int timer = 1;
int cnt = 1;
int component[200100];

void dfs1(int u, int p = -1) {
    disc[u] = timer++;
    low[u] = disc[u];
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, en = graph[u][i].second;
        if (disc[v] == 0) {
            dfs1(v, u);
            if (low[v] > disc[u]) {
                bridges.push_back(en);
                bridge[en] = 1;
            }
            low[u] = min(low[u], low[v]);
        }
        else if (v != p)
            low[u] = min(low[u], disc[v]);
    }
}

void dfs2(int u, int cmp) {
    component[u] = cmp;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, en = graph[u][i].second;
        if (component[v] == 0) {
            if (bridge[en]) {
                cnt++;
                tree[cmp].push_back(cnt);
                tree[cnt].push_back(cmp);
                dfs2(v, cnt);
            }
            else
                dfs2(v, cmp);
        }
    }
}

int p[32][201000];
int level[200100];

void dfs3(int u, int parent = -1) {
    p[0][u] = parent;
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        if (v != parent) {
            level[v] = level[u] + 1;
            dfs3(v, u);
        }
    }
}

int lca(int u, int v) {
    if (level[u] < level[v])
        swap(u, v);

    int diff = level[u] - level[v];
    for (int i = 25; i >= 0; i--)
        if ((diff >> i) & 1)
            u = p[i][u];

    if (u == v)
        return u;

    for (int i = 25; i >= 0; i--) {
        if (p[i][u] != -1 && p[i][u] != p[i][v])
            u = p[i][u], v = p[i][v];
    }

    return p[0][u];
}

int main(void) {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(make_pair(v, i));
        graph[v].push_back(make_pair(u, i));
        edges.push_back(make_pair(u, v));
    }
    dfs1(1);
    dfs2(1, 1);
    memset(p, -1, sizeof(p));
    dfs3(1);
    // now calc lca dp array
    for (int i = 1; (1 << i) < cnt; i++)
        for (int j = 1; j <= cnt; j++)
            if (p[i - 1][j] != -1)
                p[i][j] = p[i - 1][p[i - 1][j]];
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        int cu = component[u], cv = component[v];
        int ancestor = lca(cu, cv);
        int ans = level[cu] + level[cv] - 2 * level[ancestor];
        printf("%d\n", ans);
    }
    return 0;
}
