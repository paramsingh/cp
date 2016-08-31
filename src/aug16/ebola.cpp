#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10010];
int w[10010];
int nw[10010];
int depth[10010];
int infected[10010];
int vaccinated[10010];

struct node {
    int id;
    double priority;
    node(int b, int c) {
        id = b, priority = c;
    }
    bool operator<(const node& a) const {
        return priority < a.priority;
    }
};

int visited[10010];
int dfs(int u, int depth = 3) {
    visited[u] = 1;
    int ans = w[u];
    if (depth == 0)
        return ans;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v])
            ans += dfs(v, depth - 1);
    }
    return ans;
}


int main(void) {
    int n, m, k, s;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    infected[s] = 1;

    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    queue<int> q;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (depth[v] == 0) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        nw[i] = 1000 * w[i] + 200 * graph[i].size() - 400 * depth[i];

    memset(depth, 0, sizeof(depth));
    priority_queue<node> pq;
    for (int i = 1; i <= n; i++)
        if (!infected[i])
            pq.push(node(i, nw[i]));
    depth[s] = 1;
    q.push(s);
    int nxttime = 2, done = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (depth[u] == nxttime) {
            nxttime++;
            while (!pq.empty()) {
                node n = pq.top();
                pq.pop();
                if (!infected[n.id]) {
                    depth[n.id] = 0;
                    vaccinated[n.id] = 1;
                    printf("%d ", n.id);
                    done++;
                    break;
                }
            }

            if (pq.empty() || done == k)
                break;
        }

        infected[u] = 1;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!vaccinated[v] && depth[v] == 0) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = done; i < k; i++)
        printf("%d ", s);
    return 0;
}

