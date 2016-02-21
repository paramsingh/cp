#include <bits/stdc++.h>
#define INF 100000000000
using namespace std;

class oasis {
    public:
        int u;
        double temp, dist;
        oasis(int lu, double lt, double ld) {
            u = lu, temp = lt, dist = ld;
        }
};

class cmp {
    public:
        bool operator() (const oasis& a, const oasis& b) {
            if (a.temp == b.temp)
                return a.dist > b.dist;
            return a.temp > b.temp;
        }
};

vector<int> graph[200];
vector<double> t[200];
vector<double> d[200];

double mintemp[200];
double dis[200];
int done[200];
int prev[200];

int main(void) {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        for (int i = 0; i <= n; i++) {
            graph[i].clear();
            t[i].clear();
            d[i].clear();
            mintemp[i] = dis[i] = INF;
            prev[i] = -1;
            done[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            double temp, w;
            scanf("%d %d %lf %lf", &u, &v, &temp, &w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            t[u].push_back(temp);
            d[u].push_back(w);
            t[v].push_back(temp);
            d[v].push_back(w);
        }
        mintemp[src] = 0;
        dis[src] = 0;
        priority_queue<oasis, vector<oasis>, cmp> pq;
        pq.push(oasis(src, 0, 0));
        while (!pq.empty()) {
            oasis cur = pq.top();
            pq.pop();
            int u = cur.u; double temp = cur.temp, di = cur.dist;
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                double et = t[u][i];
                double mn = max(et, temp);
                double w = d[u][i];
                if (!done[v] && mintemp[v] > mn) {
                    mintemp[v] = mn;
                    pq.push(oasis(v, mn, dis[v]));
                }
            }
            done[u] = 1;
        }
        double limit = mintemp[dest];
        pq.push(oasis(src, 0, 0));
        memset(done, 0, sizeof(done));
        dis[src] = 0;
        while (!pq.empty()) {
            oasis cur = pq.top();
            pq.pop();
            int u = cur.u;
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                double temp = t[u][i];
                if (done[v] || t[u][i] > limit)
                    continue;
                if (dis[v] > dis[u] + d[u][i]) {
                    dis[v] = dis[u] + d[u][i];
                    prev[v] = u;
                    pq.push(oasis(v, 0, dis[v]));
                }
            }
            done[u] = 1;
        }
        vector<int> path;
        int cur = dest;
        while (cur != src) {
            path.push_back(cur);
            cur = prev[cur];
        }
        path.push_back(src);
        for (int i = path.size() - 1; i > 0; i--)
            printf("%d ", path[i]);
        printf("%d\n", path[0]);
        printf("%0.1lf %0.1lf\n", dis[dest], mintemp[dest]);

    }
    return 0;
}
