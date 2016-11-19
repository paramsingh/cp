#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int p[200100];
int find(int u) {
    return (p[u] == u) ? u : (p[u] = find(u));
}

void join(int u, int v) {
    int pu = find(u), pv = find(v):
    p[pu] = pv;
}

struct edge {
    int u, v, w, c, id;
    edge(int a, int b, int e, int d, int f) {
        u = a, v = b, w = e, c = d, id = f;
    }
    bool operator< (const edge& a) const {
        return w < a.w;
    }
} edges[200100], dup[200100];

bool cmp(int a, int b) {
    if (edges[a].c == edges[b].c)
        return edges[a].w < edges[b].w;
    return edges[a].c < edges[b].c;
}

int done[200100];
vector<edge> graph[200100];
int pa[32][200100];
int mx[32][200100];
ll sum;
multiset<int> mp;

void dfs1(int u, int p, int w, int c) {
    mx[0][u] = w;
    pa[0][u] = p;
    if (w != -1) {
        sum += w;
        mp.insert(c);
    }
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].v, w = graph[u][i].w, c = graph[u][i].c;
        if (v != p)
            dfs1(v, u, w, c);
    }
}

int main(void) {
    for (int i = 1; i <= 200100; i++)
        p[i] = i;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &edges[i].w);
        edges[i].id = i;
    }
    for (int i = 1; i <= m; i++)
        scanf("%d", &edges[i].c);
    for (int i = 1; i <= m; i++)
        scanf("%d %d", &edges[i].u, &edges[i].v);
    for (int i = 1; i <= m; i++) {
        dup[i].u = edges[i].u;
        dup[i].v = edges[i].v;
        dup[i].w = edges[i].w;
        dup[i].c = edges[i].c;
        dup[i].id = edges[i].id;
    }
    sort(edges + 1, edges + m + 1);
    for (int i = 1; i <= m; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (find(u) != find(v)) {
            join(u, v);
            graph[u].push_back(edge(u, v, edges[i].w, edges[i].c, edges[i].id));
            graph[v].push_back(edge(v, u, edges[i].w, edges[i].c, edges[i].id));
            done[edges[i].id] = 1;
        }
    }
    memset(pa, -1, sizeof(pa));
    memset(mx, -1, sizeof(mx));
    dfs1(1, -1);
    for (int lg = 1; lg <= 20; lg++) {
        for (int i = 1; i <= n; i++) {
            if (pa[lg - 1][i] != -1) {
                pa[lg][i] = pa[lg - 1][pa[lg - 1][i]];
                mx[lg][i] = max(mx[lg - 1][i], mx[lg - 1][pa[lg - 1][i]]);
            }
        }
    }
    ll ans
}
