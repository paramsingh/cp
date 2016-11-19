#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
ll up[100100];
ll down[100100];
int a[100100];

vector<int> graph[100100];

void dfs(int u, int p) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != p) {
            dfs(v, u);
            up[u] = max(up[u], up[v]);
            down[u] = max(down[u], down[v]);
        }
    }
    ll val = a[u] + up[u] - down[u];
    if (val < 0)
        up[u] -= val;
    else
        down[u] += val;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(1, -1);
    printf("%lld\n", up[1] + down[1]);
    return 0;
}
