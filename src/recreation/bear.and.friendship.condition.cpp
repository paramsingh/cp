#include <bits/stdc++.h>
using namespace std;


vector<int> graph[150100];
int cmp = 1;

int done[150010];
int size[150100];
int component[150100];

void get_component_details(int u) {
    component[u] = cmp;
    size[cmp]++;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (component[v] != 0) continue;
        get_component_details(v);
    }
}

int check(int u, int cmp) {
    if (component[u] != cmp)
        return 1;
    if (graph[u].size() != size[cmp] - 1)
        return 1;
    done[u] = 1;
    int flag = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (done[v]) continue;
        flag |= check(v, cmp);
    }
    return flag;
}


int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (component[i]) continue;
        cmp++;
        get_component_details(i);
        flag = flag | check(i, cmp);
    }

    printf("%s\n", flag ? "NO" : "YES");
    return 0;
}
