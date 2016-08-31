#include <bits/stdc++.h>
using namespace std;

inline int scan() {
    register int x = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar_unlocked();
    }
    return x;
}

int a[100100];
int n;
vector<int> graph[100100];

int parent[20][100100];
int depth[100100];

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    parent[0][u] = p;
    for (int i = 0; i < graph[u].size(); i++) {
        if (p != graph[u][i])
            dfs(graph[u][i], u);
    }
}

int query(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int log;
    for (log = 1; (1 << log) <= depth[u]; log++);
    log--;

    for (int i = log; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v])
            u = parent[i][u];
    }

    if (u == v)
        return v;

    for (int i = log; i >= 0; i--) {
        if (parent[i][u] != -1 && parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

int* path(int u, int v, int lca, int pl) {
    int* arr = (int*) calloc(pl + 1, sizeof(int));
    int cnt = 0;
    while (u != lca) {
        arr[cnt++] = a[u];
        u = parent[0][u];
    }
    arr[cnt++] = a[u];
    while (v != lca) {
        arr[--pl] = a[v];
        v = parent[0][v];
    }
    return arr;
}

void rev(int u, int v) {
    int lca = query(u, v);
    int l = depth[u] + depth[v] - 2*depth[lca] + 1;
    int *arr = path(u, v, lca, l);
    int x = l - 1;
    while (u != lca) {
        a[u] = arr[x];
        x--;
        u = parent[0][u];
    }
    a[lca] = arr[x];
    x = 0;
    while (v != lca) {
        a[v] = arr[x];
        x++;
        v = parent[0][v];
    }
    free(arr);
}

int equal(int u1, int v1, int u2, int v2) {
    int lca1 = query(u1, v1);
    int lca2 = query(u2, v2);
    int l = depth[u1] + depth[v1] - 2*depth[lca1] + 1;
    int *arr1 = path(u1, v1, lca1, l);
    int *arr2 = path(u2, v2, lca2, l);
    for (int i = 0; i < l; i++) {
        if (arr1[i] != arr2[i]) {
            free(arr1);
            free(arr2);
            return 0;
        }
    }
    free(arr1);
    free(arr2);
    return 1;
}

void copy(int u1, int v1, int u2, int v2) {
    int lca1 = query(u1, v1);
    int lca2 = query(u2, v2);
    int l = depth[u1] + depth[v1] - 2 * depth[lca1] + 1;
    int *arr1 = path(u1, v1, lca1, l);
    int cnt = 0;
    while (u2 != lca2) {
        a[u2] = arr1[cnt];
        cnt++;
        u2 = parent[0][u2];
    }
    a[lca2] = arr1[cnt];
    cnt = l - 1;
    while (v2 != lca2) {
        a[v2] = arr1[cnt];
        cnt--;
        v2 = parent[0][v2];
    }
    free(arr1);
}


int main(void) {
    int q;
    n = scan();
    q = scan();
    for (int i = 1; i <= n; i++)
        a[i] = scan();

    for (int i = 0; i < n - 1; i++) {
        int u = scan(), v = scan();
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));
    depth[1] = 0;
    dfs(1, -1);
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[j - 1][i] != -1)
                parent[j][i] = parent[j - 1][parent[j - 1][i]];
        }
    }

    while (q--) {
        int type = scan();
        if (type == 1) {
            int u = scan(), v = scan();
            rev(u, v);
        }
        else {
            int u1 = scan(), v1 = scan();
            int u2 = scan(), v2 = scan();
            if (type == 2) {
                if (equal(u1, v1, u2, v2))
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            else {
                copy(u1, v1, u2, v2);
            }
        }
    }
    return 0;
}
