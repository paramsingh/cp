#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 100;

int n, m, k, s;
int a[100100];
vector<int> graph[100100];
int dist[110][100100];

void calculate_distances_to_good(int good) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        dist[good][i] = inf;
        if (a[i] == good) {
            dist[good][i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (dist[good][v] != inf) continue;
            dist[good][v] = dist[good][u] + 1;
            q.push(v);
        }
    }
}


int main(void) {
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int good = 1; good <= k; good++)
        calculate_distances_to_good(good);
    for (int i = 1; i <= n; i++) {
        vector<int> costs;
        for (int j = 1; j <= k; j++)
            costs.push_back(dist[j][i]);
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int j = 0; j < s; j++)
            ans += costs[j];
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}
