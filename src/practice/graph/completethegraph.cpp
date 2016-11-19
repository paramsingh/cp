#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
const ll inf = 1e18;

struct edge {
    int u, v, id;
    ll w;
    edge(int a, int b, ll c, int d) {
        u = a, v = b, w = c, id = d;
    }
};

vector<edge> graph[100100];
vector<edge> edges;

int erased[100100];
int done[100100];
ll fromt[100100];
ll froms[100100];

struct cmp {
    bool operator() (const pil& a, const pil& b) {
        return a.second > b.second;
    }
};

int main(void) {
    int n, m, l, s, t;
    scanf("%d %d %d %d %d", &n, &m, &l, &s, &t);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (w == 0) {
            w = 1;
            erased[i] = 1;
        }
        graph[u].push_back(edge(u, v, w, 2*i));
        graph[v].push_back(edge(v, u, w, 2*i + 1));
        edges.push_back(edge(u, v, w, i));
    }
    for (int i = 0; i < n; i++)
        fromt[i] = froms[i] = inf;

    // dijkstra from t
    priority_queue<pil, vector<pil>, cmp> pq;
    fromt[t] = 0;
    pq.push(make_pair(t, 0));
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        done[u] = 1;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].v, w = graph[u][i].w;
            if (done[v] == 0 && fromt[v] > fromt[u] + w) {
                fromt[v] = fromt[u] + w;
                pq.push(make_pair(v, fromt[v]));
            }
        }
    }
    // start dijkstra from s
    memset(done, 0, sizeof(done));
    froms[s] = 0;
    pq.push(make_pair(s, 0));
    while (!pq.empty()) {
        int u = pq.top().first; ll w = pq.top().second;
        pq.pop();
        done[u] = 1;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].v, wt = graph[u][i].w;
            int id = graph[u][i].id;
            if (done[v] == 0) {
                if (erased[id / 2] && w + wt + fromt[v] < l) {
                    graph[u][i].w = max(1LL, l - w - fromt[v]);
                    edges[id/2].w = max(edges[id/2].w, max(1LL, l - w - fromt[v]));
                }
                if (froms[v] > graph[u][i].w + froms[u]) {
                    froms[v] = froms[u] + graph[u][i].w;
                    pq.push(make_pair(v, froms[v]));
                }
            }
        }
    }

    if (froms[t] != l) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int i = 0; i < edges.size(); i++) {
        printf("%d %d %lld\n", edges[i].u, edges[i].v, edges[i].w);
    }
    return 0;
}
