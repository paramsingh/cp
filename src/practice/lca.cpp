#include <cstdio>
#include <cstdlib>
#include <vector>
#define N 1034
#define DEPTH 12
using namespace std;

struct node {
    vector<int> adj;
    int depth;
    int parent;
};

struct node* tree;
int **pa;
int n;

void dfs(int cur, int prev, int depth) {
    pa[0][cur] = prev;
    tree[cur].parent = prev;
    tree[cur].depth = depth;
    int i;
    for (i = 0; i < tree[cur].adj.size(); i++) {
        if (tree[cur].adj[i] != prev) {
            dfs(tree[cur].adj[i], cur, depth+1);
        }
    }
}

int lca(int u, int v) {
    if (tree[u].depth < tree[v].depth) {
        int temp = u;
        u = v;
        v = temp;
    }
    int i;
    for (i = 10; i >= 0; i--) {
        if (tree[u].depth - (1 << i) >= tree[v].depth)
            u = pa[i][u];
    }
    if (u == v)
        return v;

    for (i = 10; i >= 0; i--) {
        if (pa[i][u] != -1 && pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

int main(void) {
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        printf("Case %d:\n", c++);
        scanf("%d", &n);
        tree = (struct node*) calloc(1034, sizeof(struct node));
        pa = (int**) calloc(DEPTH+4, sizeof(int*));
        int i, j;
        for (i = 0; i < DEPTH+4; i++) {
            pa[i] = (int*) calloc(N, sizeof(int));
            for (j = 0; j < n; j++)
                pa[i][j] = -1;
        }
        for (i = 0; i < n; i++) {
            int x, c;
            scanf("%d", &x);
            while (x--) {
                scanf("%d", &c);
                tree[i].adj.push_back(c-1);
                tree[c-1].adj.push_back(i);
            }
        }
        dfs(0, -1, 0);
        for (i = 1; i < DEPTH; i++) {
            for (j = 0; j < n; j++) {
                if (pa[i-1][j] != -1) {
                    pa[i][j] = pa[i-1][pa[i-1][j]];
                }
            }
        }
        int m;
        scanf("%d", &m);
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", lca(u-1, v-1) + 1);
        }
    }
    return 0;
}

