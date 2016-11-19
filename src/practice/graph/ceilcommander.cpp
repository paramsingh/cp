#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
set<int> graph[100100];

int subtree[100100];
int color[100100];
int cmp;

void dfs1(int u, int p = -1) {
    subtree[u] = 1;
    for (auto v: graph[u]) {
        if (v == p) continue;
        dfs1(v, u);
        subtree[u] += subtree[v];
    }
}

int centroid(int u, int p = -1) {
    for (auto v: graph[u]) {
        if (v == p) continue;
        if (subtree[v] > cmp / 2)
            return centroid(v, u);
    }
    return u;
}

void go(int u, int clr, int p = -1) {
    if (clr > 25) {
        printf("-1\n");
        exit(0);
    }
    dfs1(u);
    cmp = subtree[u];
    int nxt = centroid(u);
    color[nxt] = clr;
    for (auto v: graph[nxt]) {
        graph[v].erase(nxt);
        go(v, clr + 1, u);
    }
}


int main(void) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }
    go(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%c ", 'A' + color[i]);
    printf("\n");
}
