#include <bits/stdc++.h>
using namespace std;

int adj[1010][1010];
int color[1010];
int n, m;

int dfs(int u) {
    for (int v = 1; v <= n; v++) {
        if (v == u)
            continue;
        if (adj[u][v] == 1 && color[v] == -1) {
            color[v] = 1 - color[u];
            int f = dfs(v);
            if (f == 0)
                return 0;
        }
        else if (adj[u][v] == 1 && color[v] == color[u])
            return 0;
    }
    return 1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = 1;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = 0;
            adj[v][u] = 0;
        }
        memset(color, -1, sizeof(color));
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                color[i] = 1;
                int x = dfs(i);
                if (x == 0) {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
