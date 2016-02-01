// http://codeforces.com/problemset/problem/61/D

#include <bits/stdc++.h>
#define MAX 100010
#define mp make_pair
using namespace std;
typedef long long int lli;

class edge {
    public:
        int u, v;
        lli w;
        edge(int _u, int _v, lli _w) {
            u = _u;
            v = _v;
            w = _w;
        }
};

typedef pair<int, lli> pii;

vector<edge> edges;
vector<pii> tree[MAX];
int visited[MAX] = {0};
int n, m;

lli dfs(int cur, lli path) {
    visited[cur] = 1;
    lli p = path;
    for (int i = 0; i < tree[cur].size(); i++) {
        int v = tree[cur][i].first;
        lli w = tree[cur][i].second;
        if (visited[v] == 0) {
            lli lp = dfs(v, path + w);
            if (p < lp)
                p = lp;
        }
    }
    return p;
}

int main(void) {
    cin >> n;
    m = n - 1;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
        tree[u].push_back(mp(v, (lli) w));
        tree[v].push_back(mp(u, (lli) w));
    }

    lli path = dfs(1, 0);
    lli sum = 0;
    for (int i = 0; i < m; i++)
        sum += (edges[i].w << 1);
    sum -= path;
    cout << sum << endl;
    return 0;
}
