// Hopcroft Karp algorithm for maximum bipartite matching
// Complexity: O(|E| * (|V| ^ 1/2))

#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

vector<int> graph[50100];
int lpair[50100];
int rpair[50100];
int dist[50100];
int n, m, p;
int bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (lpair[i] == 0) {
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
                if (dist[ rpair[v] ] == INF) {
                    dist[ rpair[v] ] = dist[u] + 1;
                    q.push(rpair[v]);
                }
            }
        }
    }
    return dist[0] != INF;
}

int dfs(int u) {
    if (u == 0)
        return 1;
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
    return 0;
}


int hopcroft() {
    for (int i = 1; i <= n; i++)
        lpair[i] = 0;
    for (int i = 1; i <= m; i++)
        rpair[i] = 0;
    int match = 0;
    while (bfs()) {
        for (int i = 1; i <= n; i++) {
            if (lpair[i] == 0)
                if (dfs(i))
                    match++;
        }
    }
    return match;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < p; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }
    printf("%d\n", hopcroft());
    return 0;
}
