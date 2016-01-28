// http://codeforces.com/problemset/problem/14/D

#include <bits/stdc++.h>
#define MAX 300
using namespace std;
typedef pair<int, int> pii;

int adj[MAX][MAX] = {0};
int n;
int done[MAX][MAX] = {0};

pii dfs(int cur, int prev, int val) {
    int i;
    int mx = val;
    int index = cur;
    for (i = 0; i < n; i++) {
        if (i != prev && adj[cur][i] == 1) {
            pii x = dfs(i, cur, val+1);
            if (mx < x.first) {
                mx = x.first;
                index = x.second;
            }
        }
    }
    return make_pair(mx, index);
}

int lp(int beg) {
    pii f = dfs(beg, -1, 0);
    return dfs(f.second, -1, 0).first;
}


int main(void) {
    scanf("%d", &n);
    int i, j;
    for (i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u][v] = adj[v][u] = 1;
    }
    int mx = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (done[i][j] == 0 && adj[i][j] == 1) {
                done[i][j] = done[j][i] = 1;
                adj[i][j] = adj[j][i] = 0;
                int a = lp(i);
                int b = lp(j);
                int x = a * b;
                if (mx < x)
                    mx = x;
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    printf("%d\n", mx);
    return 0;
}
