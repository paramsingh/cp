#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;

int dist[4000][4000];
vector<int> graph[4000];
vector<pii> ng[4000];
int ndist[4000][4000][10];
int parent[4000][4000][10];

struct state {
    int v, depth, wt;
    state(int a, int b, int c) {
        v = a, depth = b, wt = c;
    }
};

class cmp {
    public:
        bool operator() (const state& a, const state& b) {
            return a.wt < b.wt;
        }
};

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int j = 0; j < graph[u].size(); j++) {
                int v = graph[u][j];
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != -1 && i != j) {
                ng[i].push_back(make_pair(j, dist[i][j]));
            }
        }
    }

    printf("hello\n");
    for (int i = 0; i < 4000; i++) {
        for (int j = 0; j < 4000; j++) {
            for (int k = 0; k < 10; k++)
                ndist[i][j][k] = INF;
        }
    }
    int mx = -1, src, fourth;
    for (int i = 1; i <= n; i++) {
        ndist[i][i][0] = 0;
        priority_queue<state, vector<state>, cmp> pq;
        pq.push(state(i, 0, 0));
        while (!pq.empty()) {
            state a = pq.top();
            int u = a.v, d = a.depth, w = a.wt;
            pq.pop();
            if (ndist[i][u][d] > w) continue;
            if (d == 4) continue;
            for (int j = 0; j < ng[u].size(); j++) {
                int v = ng[u][j].first;
                int w = ng[u][j].second;
                int flag = 0;
                if (v == i)
                    flag = 1;
                int x = u;
                int cd = d;
                while (x != i) {
                    if (x == v)
                        flag = 1;
                    x = parent[i][x][d];
                    d--;
                }
                if (flag == 1)
                    continue;
                else if (ndist[i][v][d+1] < ndist[i][u][d] + w) {
                    parent[i][v][d+1] = u;
                    ndist[i][v][d+1] = ndist[i][u][d] + w;
                    pq.push(state(v, d+1, ndist[i][v][d+1]));
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (mx < ndist[i][4][j]) {
                mx = ndist[i][4][j];
                src = i;
                fourth = j;
            }
        }
    }
    vector<int> ans;
    int x = fourth;
    int d = 4;
    while (x != src) {
        ans.push_back(x);
        x = parent[src][x][d];
        d--;
    }
    printf("%d ", src);
    for (int i = 2; i >= 0; i--)
        printf("%d ", ans[i]);
    return 0;
}


