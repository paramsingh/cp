#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

vector<pii> graph[400100];
vector<pii> edges;
int cmp[400100];
int cut[400100];
int sz[400100];
int in[400100];
int low[400100];
int rev[400100];
int done[400100];
int visited[400100];
int timer = 1, cnt = 1;
int n, m;

int mxcmp, mxcmps;

void getcuts(int u = 1, int p = -1) {
    in[u] = timer++;
    low[u] = in[u];
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, id = graph[u][i].second;
        if (in[v] == 0) {
            getcuts(v, u);
            if (low[v] > in[u])
                cut[id] = 1;
        }
        if (v != p)
            low[u] = min(low[u], low[v]);
    }
}

void dfs(int u, int cmpno) {
    cmp[u] = cmpno;
    sz[cmpno]++;
    if (mxcmps < sz[cmpno]) {
        mxcmps = sz[cmpno];
        mxcmp = cmpno;
    }
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, id = graph[u][i].second;
        if (cmp[v] == 0) {
            if (cut[id]) {
                cnt++;
                dfs(v, cnt);
            }
            else
                dfs(v, cmpno);
        }
    }
}

void orient(int u) {
    visited[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, id = graph[u][i].second;
        if (visited[v] == 0) {
            if (cut[id])
                edges[id].first = v, edges[id].second = u;
            else
                edges[id].first = u, edges[id].second = v;
            done[id] = 1;
            orient(v);
        }
        else {
            if (done[id]) continue;
            if (cut[id])
                edges[id].first = v, edges[id].second = u;
            else
                edges[id].first = u, edges[id].second = v;
            done[id] = 1;
        }
    }
}


int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(make_pair(v, i));
        graph[v].push_back(make_pair(u, i));
        edges.push_back(make_pair(u, v));
    }

    getcuts();
    mxcmps = -1;
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0 && cmp[i] == mxcmp)
            orient(i);
    }
    printf("%d\n", mxcmps);
    for (int i = 0; i < edges.size(); i++) {
        printf("%d %d\n", edges[i].first, edges[i].second);
    }
    return 0;
}
