#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int parent[2010];
int find(int u) {
    if (parent[u] == u)
        return u;
    else
        return parent[u] = find(parent[u]);
}

int join(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    parent[pu] = pv;
}

struct edge {
    int u, v, w;
    edge(int a, int b, int c): u(a), v(b), w(c) {}
    bool operator<(const edge& a) {
        return w < a.w;
    }
};

vector<edge> edges;
vector<pii> tree[2010];
int adj[2010][2010];
ll dist[2010][2010];

void dfs(int root, int u, int p) {
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i].first, w = tree[u][i].second;
        if (v != p) {
            dist[root][v] = dist[root][u] + w;
            dfs(root, v, u);
        }
    }
}

int main(void) {
    for (int i = 1; i < 2010; i++)
        parent[i] = i;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
            if (i != j)
                edges.push_back(edge(i, j, adj[i][j]));
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            tree[u].push_back(make_pair(v, w));
            tree[v].push_back(make_pair(u, w));
            join(u, v);
        }
    }

    int flag = 1;
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        dfs(i, i, -1);
        for (int j = 1; j <= n; j++)
            if (dist[i][j] != adj[i][j] || (i != j && dist[i][j] == 0))
                flag = 0;
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
