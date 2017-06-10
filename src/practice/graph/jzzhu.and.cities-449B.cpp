#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;


struct edge {
    int v, w, type, id;
    edge(int a, int b, int x, int c) {
        v = a, w = b, type = x, id = c;
    }
};
vector<edge> graph[100100];

int in_dag[1000100];

struct cmp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

ll dist[100100];
int in[100100];
int done[1000100];

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int edge_id = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(edge(v, w, 0, ++edge_id));
        graph[v].push_back(edge(u, w, 0, ++edge_id));
    }
    for (int i = 1; i <= k; i++) {
        int v, w;
        scanf("%d %d", &v, &w);
        graph[v].push_back(edge(1, w, 1, ++edge_id));
        graph[1].push_back(edge(v, w, 1, ++edge_id));
    }

    // run dijkstra to find all shortest paths first
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    for (int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[1] = 0;
    pq.push(make_pair(1, dist[1]));
    while (!pq.empty()) {
        int u = pq.top().first, d = pq.top().second;
        pq.pop();
        if (done[u]) continue;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].v, w = graph[u][i].w;
            if (done[v] == 0 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(v, dist[v]));
            }
        }
        done[u] = 1;
    }


    // now make the shortest path DAG
    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].v, w = graph[u][i].w, id = graph[u][i].id;
            if (dist[v] == dist[u] + w) {
                if (in_dag[id]) continue;
                in_dag[id] = 1;
                in[v]++;
            }
        }
    }

    // remove the edges not needed and count them
    int cnt = 0;
    for (int i = 0; i < graph[1].size(); i++) {
        int type = graph[1][i].type;
        if (type == 1) {
            int id =  graph[1][i].id;
            int v = graph[1][i].v;
            if (in_dag[id] == 0) {
                cnt++;
            }
            else if (in[v] > 1) {
                cnt++;
                in[v]--;
            }
        }
    }
    printf("%d\n", cnt);
}
