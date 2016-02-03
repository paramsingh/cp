// http://codeforces.com/problemset/problem/144/D

#include <bits/stdc++.h>
#define MAX 100010
#define mp make_pair
using namespace std;
typedef long long int lli;
typedef pair<int, lli> pii;

int n, m, s;

class pri {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

vector<pii> graph[MAX];
lli dis[MAX];
bool done[MAX];
int parent[MAX];

class ege {
    public:
        int u, v;
        lli w;
        ege(int a, int b, lli c) {
            u = a; v = b; w = c;
        }
};

vector<ege> edges;

int main(void) {
    cin >> n >> m >> s;
    int dup = m;
    while (dup--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(mp(v, (lli) w));
        graph[v].push_back(mp(u, (lli) w));
        edges.push_back(ege(u, v, w));
    }
    lli req;
    cin >> req;
    priority_queue<pii, vector<pii>, pri> pq;
    for (int i = 1; i <= n;i++) {
        dis[i] = LLONG_MAX;
        done[i] = false;
    }
    dis[s] = 0;
    int ans = 0;
    pq.push(mp(s, 0));
    while (!pq.empty()) {
        int u = pq.top().first;
        lli d = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            lli w = graph[u][i].second;
            if (!done[v] && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                parent[v] = u;
                pq.push(mp(v, dis[v]));
            }
        }
        done[u] = true;
    }
    int l = req;
    int edge = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        lli w = edges[i].w;
        if (req < dis[u] + w && w - req + dis[u] + dis[v] > req && dis[u] < req) {
            edge++;
        }
        if (req < dis[v] + w && w - req + dis[v] + dis[u] > req && dis[v] < req) {
            edge++;
        }
        if (dis[v] < req && dis[u] < req && dis[u] + dis[v] + w == 2*req) {
            edge++;
        }
    }
    for (int i = 1; i <= n; i++)
        if (dis[i] == req)
            edge++;
    cout << edge << endl;
    return 0;
}
