// Subway: http://codeforces.com/contest/131/problem/D

#include <bits/stdc++.h>
using namespace std;

int n;
int parent[4000] = {0};
int len[4000] = {0};
vector<int> graph[4000];

int dfs(int node, int l) {
    len[node] = l;
    for (int i = 0; i < graph[node].size(); i++) {
        int v = graph[node][i];
        if (v == parent[node])
            continue;
        if (len[v] != 0)
            return len[v];
        parent[v] = node;
        int tmp = dfs(v, l + 1);
        if (tmp > -1)
            return tmp;
    }
    return -1;
}


int main(void) {
    scanf("%d", &n);
    int m = n;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", dfs(i, 1) - 1);
        for (int j = 1; j <= n; j++) {
            parent[j] = len[j] = 0;
        }
    }
    return 0;
}
