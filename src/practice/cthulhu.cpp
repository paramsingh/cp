// http://codeforces.com/problemset/problem/104/C
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int cycles = 0;
vector<int> graph[200];
int done[200][200] = {0};
int visited[200] = {0};
int c = 0;

void dfs(int cur, int prev) {
    c++;
    visited[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int v = graph[cur][i];
        if (!done[cur][v] && !done[v][cur]) {
            done[cur][v] = 1;
            done[v][cur] = 1;
            if (v != prev && visited[v] == 1) {
                cycles++;
                continue;
            }
            dfs(v, cur);
        }
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    if (c != n)
        printf("NO\n");
    else if (cycles == 1)
        printf("FHTAGN!\n");
    else
        printf("NO\n");
    return 0;
}
