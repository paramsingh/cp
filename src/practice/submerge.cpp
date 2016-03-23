// find the articulation points in a graph
// A vertex in the dfs tree is an articulation point iff
// 1. it is the root and has more than one children
// 2. it is not the root and it's subtree does not have a single backedge
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10010];
int low[10010];
int disc[10010];
int tim = 0, ans = 0;
int parent[10010];
int visited[10010];

void dfs(int u) {
    visited[u] = 1;
    low[u] = disc[u] = tim++;
    int children = 0;
    int flag = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (visited[v] == 0) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            children++;
            if (u == 1 && children > 1)
                flag = 1;
            if (u != 1 && low[v] >= disc[u])
                flag = 1;
        }
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
    ans += flag;
}

int main(void) {
    int n, m;
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            parent[i] = -1;
            visited[i] = 0;
            disc[i] = 0;
            low[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        ans = 0; tim = 1;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}

