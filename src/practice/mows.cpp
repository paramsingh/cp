#include <bits/stdc++.h>
#define MAX 110060
using namespace std;

vector<int> graph[MAX];
vector<int> trans[MAX];
vector<int> topo;

int size[MAX] = {0};
int visited[MAX] = {0};
int comp[MAX] = {0};

void dfs(int cur) {
    visited[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int v = graph[cur][i];
        if (visited[v] == 0)
            dfs(v);
    }
    topo.push_back(cur);
}

int cmp = 0;

void dfs2(int cur) {
    comp[cur] = cmp;
    size[cmp] += 1;
    visited[cur] = 0;
    for (int i = 0; i < trans[cur].size(); i++) {
        int v = trans[cur][i];
        if (visited[v] == 1)
            dfs2(v);
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int h, p, s;
        scanf("%d %d %d", &h, &p, &s);
        while (s--) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            trans[v].push_back(u);
        }
        for (int i = 1; i <= h; i++) {
            if (visited[i] == 0)
                dfs(i);
        }
        cmp = 0;
        for (int i = topo.size() - 1; i >= 0; i--) {
            int u = topo[i];
            if (visited[u] == 1) {
                cmp++;
                dfs2(u);
            }
        }
        for (int i = 1; i <= h; i++)
            size[comp[i]]--;
        int mx = -1;
        int id = -1;
        for (int i = 1; i <= h; i++) {
            if (size[comp[i]] > mx) {
                mx = size[comp[i]];
                id = i;
            }
        }
        printf("%d %d\n", id, mx);
        for (int i = 0; i < MAX; i++) {
            graph[i].clear();
            trans[i].clear();
        }
        topo.clear();
        memset(size, 0, sizeof(size));
        memset(comp, 0, sizeof(comp));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}
