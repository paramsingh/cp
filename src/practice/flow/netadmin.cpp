#include <bits/stdc++.h>
#define src 1
#define sink 550
using namespace std;

class edge {
    public: int u, v, cap, flow, flag;
            edge(int a, int b, int c, int d, int f) {
                u = a, v = b, cap = c, flow = d, flag = f;
            }
            inline int rcap() { return cap - flow; }
};

vector<edge> edges;
int level[600];
int ei[600];
vector<int> graph[600];


int bfs() {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            int v = edges[id].v;
            if (level[v] != -1 || edges[id].rcap() <= 0)
                continue;
            else {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[sink] != -1;
}

int dfs(int u, int pushed) {
    if (u == sink)
        return pushed;
    if (pushed <= 0)
        return 0;
    for (; ei[u] < graph[u].size(); ei[u]++) {
        int i = ei[u];
        int id = graph[u][i];
        int v = edges[id].v;
        if (level[v] == level[u] + 1 && edges[id].rcap() > 0) {
            int x = dfs(v, min(pushed, edges[id].rcap()));
            if (x != 0) {
                edges[id].flow += x;
                edges[id^1].flow -= x;
                return x;
            }
        }
    }
    return 0;
}



int flow() {
    int f = 0;
    while (bfs()) {
        memset(ei, 0, sizeof(ei));
        while (int pushed = dfs(src, 1e8))
            f += pushed;
    }
    return f;
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        edges.clear();
        graph[src].clear();
        graph[sink].clear();
        for (int i = 1; i < 600; i++)
            graph[i].clear();
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int u, v;
        for (int i = 0; i < k; i++) {
            scanf("%d", &u);
            graph[u].push_back(edges.size());
            edges.push_back(edge(u, sink, 1, 0, 0));
            graph[sink].push_back(edges.size());
            edges.push_back(edge(sink, u, 0, 0, 0));
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            // one direction
            graph[u].push_back(edges.size());
            edges.push_back(edge(u, v, 0, 0, 1));
            graph[v].push_back(edges.size());
            edges.push_back(edge(v, u, 0, 0, 1));
            // two direction
            graph[v].push_back(edges.size());
            edges.push_back(edge(v, u, 0, 0, 1));
            graph[u].push_back(edges.size());
            edges.push_back(edge(u, v, 0, 0, 1));
        }


        int l = 0, h = 500;
        while (l < h) {
            int mid = (l + h) / 2;
            for (int i = 0; i < edges.size(); i += 2) {
                edges[i].flow = 0;
                edges[i^1].flow = 0;
                if (edges[i].flag == 1) {
                    edges[i].cap = mid;
                }
            }
            int f = flow();
            if (f >= k)
                h = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}

