#include <bits/stdc++.h>
using namespace std;

int parent[100100];
int size[100100];
int n, m;

int find(int u) {
    if (parent[u] == u)
        return u;
    else
        return parent[u] = find(parent[u]);
}

void un(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (size[pu] > size[pv]) {
        parent[pv] = pu;
        size[pv] += size[pu];
    }
    else {
        parent[pu] = pv;
        size[pu] += size[pv];
    }
}

struct edge {
    int u, v, w;
    bool operator<(const edge& a) const {
        return w < a.w;
    }
} edges[200100];

vector<pair<int, int> > graph[100100];
int subtree[100100] = {0};
unsigned long long cnt[200100] = {0};
int ans[10000100] = {0};

void dfs(int u, int p, int wt) {
    subtree[u]++;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, w = graph[u][i].second;
        if (v != p) {
            dfs(v, u, w);
            subtree[u] += subtree[v];
        }
    }
    if (wt != -1)
        cnt[wt] = subtree[u] * (long long)(n - subtree[u]);
}

int ld = 0;

void add(int x, unsigned long long n) {
    int carry = 0, cur = x;
    for (int i = 0; i < 60; i++) {
        int b = (n >> i) & 1;
        if (ans[cur] + carry + b <= 1) {
            ans[cur] = ans[cur] + carry + b;
            carry = 0;
        }
        else {
            ans[cur] = (ans[cur] + carry + b) % 2;
            carry = 1;
        }
        cur++;
    }
    while (carry == 1) {
        if (ans[cur] + carry <= 1) {
            ans[cur] = ans[cur] + carry;
            carry = 0;
        }
        else {
            ans[cur] = (ans[cur] + carry) % 2;
            carry = 1;
        }
        cur++;
    }
    ld = max(ld, cur);
}

int main(void) {
    for (int i = 0; i < 100100; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    scanf("%d %d", &n, &m);
    int mx = -1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        mx = max(mx, edges[i].w);
    }
    sort(edges, edges+m);
    int c = 0;
    for (int i = 0; c < n - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
            un(u, v);
            c++;
        }
    }

    dfs(1, -1, -1);
    for (int i = 0; i <= mx; i++) {
        if (cnt[i] > 0)
            add(i, cnt[i]);
    }
    int lead = 1;
    for (int i = ld; i >= 0; i--) {
        if (lead && ans[i] == 0)
            continue;
        else {
            printf("%d", ans[i]);
            lead = 0;
        }
    }
    printf("\n");
    return 0;
}

