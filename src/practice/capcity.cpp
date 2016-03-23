// Answer will be the number of elements in the scc of the graph with outdegree 0
// if the DAG from the SCC's is connected
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100100];
vector<int> transpose[100100];
vector<int> toposort;
vector<int> component[100100];
int scc[100100];
int cmp = 0;
int visited[100100] = {0};

void dfs(int u) {
    visited[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (visited[v] == 0)
            dfs(v);
    }
    toposort.push_back(u);
}

void dfs2(int u) {
    visited[u] = 0;
    scc[u] = cmp;
    component[cmp].push_back(u);
    for (int i = 0; i < transpose[u].size(); i++) {
        int v = transpose[u][i];
        if (visited[v] == 1)
            dfs2(v);
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        transpose[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0)
            dfs(i);
    }
    for (int i = toposort.size()-1; i >= 0; i--) {
        int u = toposort[i];
        if (visited[u] == 1) {
            cmp++;
            dfs2(u);
        }
    }
    int flag = 0;
    int scci = -1;
    for (int i = 1; i <= cmp; i++) {
        int cnt = 0;
        for (int j = 0; j < component[i].size(); j++) {
            int u = component[i][j];
            for (int k = 0; k < graph[u].size(); k++) {
                int v = graph[u][k];
                if (scc[v] != scc[u]) {
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            if (flag == 1)
                scci = -1;
            else  {
                flag = 1;
                scci = i;
            }
        }
    }
    if (scci == -1)
        printf("0\n");
    else {
        int s = component[scci].size();
        printf("%d\n", s);
        sort(component[scci].begin(), component[scci].end());
        for (int i = 0; i < component[scci].size(); i++)
            printf("%d ", component[scci][i]);
        printf("\n");
    }
    return 0;
}

