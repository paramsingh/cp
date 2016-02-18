// 14:05
#include <bits/stdc++.h>
using namespace std;

int val[100100];
vector<int> g1[100100];
vector<int> g2[100100];
int ans[100100] = {0};
int v1[100100] = {0};
int v2[100100] = {0};

void dfs(vector<int>* graph, int cur, int* visited) {
    visited[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int v = graph[cur][i];
        if (visited[v] == 0)
            dfs(graph, v, visited);
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", val+i);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (val[v] == 1)
            continue;
        else {
            g1[u].push_back(v);
            g2[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (val[i] == 1 && v1[i] == 0)
            dfs(g1, i, v1);
        else if (val[i] == 2 && v2[i] == 0)
            dfs(g2, i, v2);
    }
    for (int i = 1; i <= n; i++) {
        int ans = (int) (v1[i] && v2[i]);
        printf("%d\n", ans);
    }
    return 0;
}
