#include <bits/stdc++.h>
using namespace std;


vector<int> graph[1000];
vector<int> topo;
int done[1000];
int n, m;
int cmp = 0;
int comp[1000] = {0};

void dfs(int u) {
    done[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (done[v] == 0)
            dfs(v);
    }
    topo.push_back(u);
}

void dfs2(int u) {
    done[u] = 1;
    comp[u] = cmp;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (done[v] == 0)
            dfs2(v);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        int x = 2*u, y = 2*v;
        if (c == 0) {
            graph[x].push_back(y^1);
            graph[y].push_back(x^1);
            graph[y^1].push_back(x);
            graph[x^1].push_back(y);
        }
        else {
            graph[x].push_back(y);
            graph[y].push_back(x);
            graph[x^1].push_back(y^1);
            graph[y^1].push_back(x^1);
        }
    }
    memset(done, 0, sizeof(done));
    for (int i = 2; i <= 2*n+1; i++) {
        if (done[i] == 0)
            dfs(i);
    }

    memset(done, 0, sizeof(done));
    for (int i = topo.size() - 1; i >= 0; i--) {
        if (done[topo[i]] == 0) {
            cmp++;
            dfs2(topo[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (comp[2*i] == comp[2*i+1]) {
            printf("Impossible\n");
            return 0;
        }
    }

    memset(done, 0, sizeof(done));
    vector<int> change;
    for (int i = 0; i < topo.size(); i++) {
        int u = topo[i];
        if (done[u/2] == 0) {
            done[u/2] = 1;
            if (u % 2 == 0)
                change.push_back(u/2);
        }
    }

    printf("%d\n", (int)change.size());
    for (int i = 0; i < change.size(); i++) {
        printf("%d ", change[i]);
    }
    return 0;
}
