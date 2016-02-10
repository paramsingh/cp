// http://www.spoj.com/problems/CSTREET/

#include <bits/stdc++.h>
using namespace std;

class edge {
    public:
        int u, v, w;
        edge(int a, int b, int c) {
            u = a, v = b, w = c;
        }
};

int parent[1010];
int size[1010];

int root(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

int same(int a, int v) {
    return root(a) == root(v);
}

void un(int a, int b) {
    a = root(a);
    b = root(b);
    if (size[a] > size[b]) {
        parent[b] = a;
        size[a] += size[b];
    }
    else {
        parent[a] = b;
        size[b] += size[a];
    }
}

vector<edge> edges;

bool cmp(const edge& a, const edge& b) {
    return a.w < b.w;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        edges.clear();
        for (int i = 0; i < 1010; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        int p, n, m;
        scanf("%d %d %d", &p, &n, &m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back(edge(u, v, w));
        }
        sort(edges.begin(), edges.end(), cmp);
        long long int ans = 0;
        for (int i = 0; i < edges.size(); i++) {
            if (!same(edges[i].u, edges[i].v)) {
                un(edges[i].u, edges[i].v);
                ans += edges[i].w;
            }
        }
        printf("%lld\n", ans*p);
    }
    return 0;
}
