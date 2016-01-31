// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2031

#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define INF 1000000000000000000
using namespace std;
typedef pair<int, int> pii;
typedef long long int lli;
int n, m;

class edge {
    public: int u, v;
            double w;
            edge(int _u, int _v, double _w) {
                u = _u;
                v = _v;
                w = _w;
            }
};

vector<edge> graph;
double dist[111];

int bellman() {
    int i, j;
    int u, v;
    double w;
    for (int i = 0; i < 111; i++)
        dist[i] = 0;
    dist[1] = 0;
    for (i = 1; i < n; i++) {
        for (j = 0; j < m; j++) {
            u = graph[j].u;
            v = graph[j].v;
            w = graph[j].w;
            if (dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }
    for (i = 0; i < m; i++) {
        u = graph[i].u;
        v = graph[i].v;
        w = graph[i].w;
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            return 1;
        }
    }
    return 0;
}

int cycle(double x) {
    for (int i = 0; i < m; i++)
        graph[i].w -= x;
    int flag = bellman();
    for (int i = 0; i < m; i++)
        graph[i].w += x;
    return flag;
}

int main(void) {
    int t;
    scanf("%d", &t);
    int c = 0;
    while (t--) {
        scanf("%d %d", &n, &m);
        int u, v;
        lli w;
        lli maxe = -INF;
        lli mine = INF;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %lld", &u, &v, &w);
            graph.pb(edge(u, v, w));
            maxe = max(maxe, w);
            mine = min(mine, w);
        }
        printf("Case #%d: ", ++c);
        if (!cycle(maxe+1)) printf("No cycle found.\n");
        else {
            double l = 0, r = maxe;
            double mid;
            while (r - l > 1e-3) {
                mid = l + (r - l) / 2;
                int flag = cycle(mid);
                if (flag == 1)
                    r = mid;
                else
                    l = mid;

            }
            printf("%0.2lf\n", r);
        }
        graph.clear();
    }
    return 0;
}
