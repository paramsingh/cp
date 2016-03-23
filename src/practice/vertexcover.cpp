#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
vector<int> graph[100100];
int color[100100] = {0};
int lpair[100100];
int rpair[100100];
int dist[100100];
int n;

int bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1 && lpair[i] == 0) {
            dist[i] = 0;
            q.push(i);
        }
        else
            dist[i] = INF;
    }
    dist[0] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] < dist[0]) {
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (dist[rpair[v]] == INF) {
                    dist[rpair[v]] = dist[u] + 1;
                    q.push(rpair[v]);
                }
            }
        }
    }
    return dist[0] != INF;
}

int dfs(int u) {
    if (u != 0) {
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (dist[rpair[v]] == dist[u] + 1) {
                if (dfs(rpair[v])) {
                    rpair[v] = u;
                    lpair[u] = v;
                    return 1;
                }
            }
        }
        dist[u] = INF;
        return 0;
    }
    else return 1;
}
int matching() {
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1)
            lpair[i] = 0;
        else
            rpair[i] = 0;
    }
    int result = 0;
    while (bfs()) {
        for (int i = 1; i <= n; i++)
            if (color[i] == 1 && lpair[i] == 0)
                if (dfs(i))
                    result++;
    }
    return result;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    color[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (color[v] == 0) {
                color[v] = (color[u] == 2) ? 1 : 2;
                q.push(v);
            }
        }
    }
    printf("%d\n", matching());
    return 0;
}
