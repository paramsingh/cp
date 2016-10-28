#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> graph[200100];
int down[200100];
int l[200100];
int r[200100];
int ans = 1e9;
vector<int> nodes;

void root(int u, int p = -1) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        if (v == p)
            graph[u].erase(graph[u].begin() + i);
    }
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        if (v != p)
            root(v, u);
    }
}

void dfs1(int u) {
    down[u] = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, w = graph[u][i].second;
        dfs1(v);
        down[u] += down[v] + w;
    }
}

void dfs2(int u, int p, int up) {
    int rev = up + down[u];
    if (rev < ans) {
        ans = rev;
        nodes.clear();
        nodes.push_back(u);
    }
    else if (rev == ans)
        nodes.push_back(u);
    if (graph[u].empty())
        return;
    for (int i = 1; i < graph[u].size(); i++) {
        int prev = graph[u][i - 1].first;
        int v = graph[u][i].first;
        l[v] = l[prev] + graph[u][i - 1].second + down[prev];
    }
    for (int i = graph[u].size() - 2; i >= 0; i--) {
        int nxt = graph[u][i + 1].first;
        int v = graph[u][i].first;
        r[v] = r[nxt] + graph[u][i + 1].second + down[nxt];
    }
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, w = graph[u][i].second ^ 1;
        int push = w + l[v] + r[v] + up;
        dfs2(v, u, push);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(make_pair(v, 0));
        graph[v].push_back(make_pair(u, 1));
    }
    root(1, -1);
    dfs1(1);
    dfs2(1, -1, 0);
    sort(nodes.begin(), nodes.end());
    printf("%d\n", ans);
    for (int i = 0; i < nodes.size(); i++)
        printf("%d ", nodes[i]);
    printf("\n");
}
