#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dist[2000];
vector<pii> graph[2000];
map<pii, int> edges;

class cmp {
    public: bool operator() (const pii& a, const pii& b) {
                return a.second > b.second;
            }
};

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int src, dest, diff, p;
    scanf("%d %d %d %d", &src, &dest, &diff, &p);
    vector<int> path;
    int u, v, w;
    for (int i = 0; i < p; i++) {
        scanf("%d", &u);
        path.push_back(u);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
        edges[make_pair(u, v)] = w;
        edges[make_pair(v, u)] = w;
    }
    map<pii, pii> times;
    int t = 0;
    for (int i = 0; i < p-1; i++) {
        int u = path[i], v = path[i+1];
        times[make_pair(u, v)] = make_pair(t, t + edges[make_pair(u, v)]);
        times[make_pair(v, u)] = make_pair(t, t + edges[make_pair(u, v)]);
        t += edges[make_pair(u, v)];
    }
    for (int i = 1; i <= n; i++)
        dist[i] = 1e9;
    priority_queue<pii, vector<pii>, cmp> pq;
    dist[src] = diff;
    pq.push(make_pair(src, dist[src]));
    while (!pq.empty()) {
        u = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        if (dist[u] < d) continue;
        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i].first;
            w = graph[u][i].second;
            int add = 0;
            if (times.count(make_pair(u, v))) {
                pii range = times[make_pair(u, v)];
                if (range.first <= d && d <= range.second) {
                    add = range.second - d;
                }
            }
            if (dist[v] > dist[u] + w + add) {
                dist[v] = dist[u] + w + add;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
    printf("%d\n", dist[dest] - diff);
    return 0;
}

