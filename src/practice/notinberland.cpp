#include <bits/stdc++.h>
#define MAX 1010
#define mp make_pair
using namespace std;

int parent[MAX];
int size[MAX];

int root(int u) {
    while (u != parent[u])
        u = parent[u];
    return u;
}

int find(int u, int v) {
    return root(u) == root(v);
}

void uni(int u, int v) {
    int ru = root(u);
    int rv = root(v);
    if (size[rv] > size[ru]) {
        parent[ru] = rv;
        size[rv] += size[ru];
    }
    else {
        parent[rv] = ru;
        size[ru] += size[rv];
    }
}

typedef pair<int, int> pii;
vector<pii> can;
vector<pii> build;

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    int m = n - 1;
    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        if (find(u, v) == 1)
            can.push_back(mp(u, v));
        else
            uni(u, v);
    }
    for (int i = 2; i <= n; i++) {
        if (find(1, i) == 0) {
            uni(1, i);
            build.push_back(mp(1, i));
        }
    }
    assert(build.size() == can.size());
    int sz = build.size();
    printf("%d\n", sz);
    for (int i = 0; i < can.size(); i++) {
        int ru = can[i].first, rv = can[i].second;
        int bu = build[i].first, bv = build[i].second;
        printf("%d %d %d %d\n", ru, rv, bu, bv);
    }
    return 0;
}
