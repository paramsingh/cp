#include <bits/stdc++.h>
using namespace std;

class edge {
    public: int from, to, cap, flow, id;
    edge(int a, int b, int c, int d, int e) {
        from = a;
        to = b;
        cap = c;
        flow = d;
        id = e;
    }
    inline int rcap() {
        return cap - flow;
    }
};

vector<edge> edges;
int level[500];
int ei[500];
vector<int> graph[500];
int src, sink;

int bfs() {
    queue<int> q;
    memset(level, -1, sizeof(level));
    level[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = edges[graph[u][i]].to;
            edge& e = edges[graph[u][i]];
            if (level[v] == -1 && e.rcap() > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[sink] != -1;
}

int dfs(int u, int pushed) {
    if (pushed == 0)
        return pushed;
    if (u == sink)
        return pushed;
    for (; ei[u] < graph[u].size(); ei[u]++) {
        int id = graph[u][ei[u]];
        int v = edges[id].to;
        if (level[v] != level[u] + 1 || edges[id].rcap() <= 0)
            continue;
        int flow = dfs(v, min(pushed, edges[id].rcap()));
        if (flow > 0) {
            edges[id].flow += flow;
            edges[id^1].flow -= flow;
            return flow;
        }
    }
    return 0;
}

int dinics() {
    int flow = 0;
    while (bfs()) {
        memset(ei, 0, sizeof(ei));
        while (int pushed = dfs(src, 1e8))
            flow += pushed;
    }
    return flow;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char a[10], b[10];
        int c;
        scanf("%s", a);
        scanf("%s", b);
        scanf("%d", &c);
        char x = a[0], y = b[0];
        graph[x].push_back(edges.size());
        edges.push_back(edge(x, y, c, 0, edges.size()));
        graph[y].push_back(edges.size());
        edges.push_back(edge(y, x, 0, 0, edges.size()));
    }
    src = 'A', sink = 'Z';
    printf("%d\n", dinics());
    return 0;
}
