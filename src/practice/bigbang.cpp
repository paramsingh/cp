// http://www.lightoj.com/volume_showproblem.php?problem=1108&language=english&type=pdf

#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define INF 100000000
using namespace std;
typedef pair<int, int> pii;

class node {
    public: int u, v, w;
            node(int _u, int _v, int _w) {
                u = _u;
                v = _v;
                w = _w;
            }
};

vector<node> graph;
vector<int> rev[1010];
int ans[1010] = {0};
int n, m;

void dfs(int cur) {
    ans[cur] = 1;
    for (int i = 0; i < rev[cur].size(); i++) {
        int v = rev[cur][i];
        if (ans[v] == 0)
            dfs(v);
    }
}

int bellman() {
    int dst[n+1];
    for (int i = 0; i < n; i++)
        dst[i] = INF;
    dst[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].u;
            int v = graph[j].v;
            int w = graph[j].w;
            if (dst[v] > dst[u] + w)
                dst[v] = dst[u] + w;
        }
    }
    int flag = 0;
    for (int i = 0; i < m; i++) {
        int u = graph[i].u;
        int v = graph[i].v;
        int w = graph[i].w;
        if (dst[v] > dst[u] + w) {
            flag = 1;
            if (ans[v] == 0)
                dfs(v);
        }
    }
    return flag;
}
int main(void) {
    int t;
    scanf("%d", &t);
    int c = 0;
    while (t--) {
        printf("Case %d: ", ++c);
        scanf("%d %d", &n, &m);
        for (int i = 0; i < 1010; i++) {
            ans[i] = 0;
            rev[i].clear();
        }
        graph.clear();
        int dup = m;
        while (dup--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph.pb(node(v, u, w));
            rev[v].push_back(u);
        }
        int flag = bellman();
        if (flag == 0)
            printf("impossible\n");
        else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (ans[i] == 1) {
                    if (cnt == 0) {
                        printf("%d", i);
                        cnt++;
                    }
                    else {
                        printf(" %d", i);
                        cnt++;
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
