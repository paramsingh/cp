#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

int dsu[MAX];
int size[MAX];

int root(int x) {
    while (x != dsu[x])
        x = dsu[x];
    return x;
}

int connected(int a, int b) {
    return root(a) == root(b);
}

void un(int a, int b) {
    int ra = root(a);
    int rb = root(b);
    if (size[ra] > size[rb]) {
        dsu[rb] = ra;
        size[ra] += size[rb];
    }
    else {
        dsu[ra] = rb;
        size[rb] += size[ra];
    }
}

class query {
    public: int t, x, y;
};

query qs[MAX];
vector<int> graph[MAX];
int deg[MAX] = {0};
int in[MAX] = {0};
int out[MAX] = {0};
int timer = 1;

void dfs(int i) {
    in[i] = timer++;
    for (int j = 0; j < graph[i].size(); j++) {
        int v = graph[i][j];
        if (in[v] == 0)
            dfs(v);
    }
    out[i] = timer++;
}

int bpacket[MAX];
vector<int> req[MAX];
int ans[MAX];

int main(void) {
    for (int i = 0; i < MAX; i++) {
        dsu[i] = i;
        size[i] = 1;
        ans[i] = -1;
    }
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &qs[i].t, &qs[i].x);
        if (qs[i].t == 1 || qs[i].t == 3)
            scanf("%d", &qs[i].y);
        int y = qs[i].y, x = qs[i].x;
        if (qs[i].t == 1) {
   //         printf("%d -> %d\n", y, x);
            graph[y].push_back(x);
            deg[x]++;
        }
        else if (qs[i].t == 3) {
            req[y].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0 && deg[i] == 0)
            dfs(i);
    }
    int packet = 1;
    for (int i = 0; i < m; i++) {
        if (qs[i].t == 1) {
            un(qs[i].x, qs[i].y);
        }
        else if (qs[i].t == 2) {
            for (int j = 0; j < req[packet].size(); j++) {
                int qno = req[packet][j];
                int x = qs[qno].x;
                if (connected(qs[i].x, x) && in[x] <= in[qs[i].x] && out[x] >= out[qs[i].x])
                    ans[qno] = 1;
                else
                    ans[qno] = 0;
            }
            packet++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] == 1)
            printf("YES\n");
        else if (ans[i] == 0)
            printf("NO\n");
    }
    return 0;
}

