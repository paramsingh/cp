#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n, m, d;
int infected[100100];
vector<int> graph[100100];
int parent[100100];
int dist[100100];
int l[100100];
int r[100100];
int up[100100];

void root(int u, int p = -1) {
    parent[u] = p;
    for (int i = 0; i < graph[u].size(); i++) {
        if (graph[u][i] == p)
            graph[u].erase(graph[u].begin() + i);
    }
    for (int i = 0; i < graph[u].size(); i++)
        root(graph[u][i], u);
}

int dfs1(int u) {
    int ans = -inf;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        ans = max(ans, dfs1(v) + 1);
    }
    if (infected[u])
        ans = max(ans, 0);
    return dist[u] = ans;
}

int fin = 0;
void dfs2(int u) {
    //printf("for %d , dist = %d, up = %d\n", u, dist[u], up[u]);
    if (dist[u] <= d && up[u] <= d) {
        fin++;
    }
    if (graph[u].empty())
        return;
    int v = graph[u][0];
    l[v] = -inf;
    for (int i = 1; i < graph[u].size(); i++) {
        int prev = graph[u][i - 1];
        v = graph[u][i];
        l[v] = max(l[prev], dist[prev] + 2);
    }
    int s = graph[u].size() - 1;
    v = graph[u][s];
    r[v] = -inf;
    for (int i = s - 1; i >= 0; i--) {
        int prev = graph[u][i + 1];
        v = graph[u][i];
        r[v] = max(r[prev], dist[prev] + 2);
    }
    for (int i = 0; i < graph[u].size(); i++) {
        v = graph[u][i];
        up[v] = max(max(up[u] + 1, l[v]), r[v]);
        if (infected[u])
            up[v] = max(up[v], 1);
        dfs2(v);
    }
}

int main(void) {
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        infected[x] = 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    root(1);
    int x = dfs1(1);
    up[1] = -inf;
    dfs2(1);
    printf("%d\n", fin);
    return 0;
}
