// http://codeforces.com/problemset/problem/107/A

#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

struct node {
    int prev, nxt;
    int pwt, nwt;
} graph[2000] = {0};

class ans {
    public: int tank, tap, dia;
} res[2000];

bool cmp(const ans& a, const ans& b) {
    return a.tank < b.tank;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int u, v, w;
    while (m--) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].nxt = v;
        graph[u].nwt = w;
        graph[v].prev = u;
        graph[v].pwt = w;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (graph[i].prev == 0) {
            int cur = i;
            res[c].tank = i;
            res[c].dia = INF;
            while (graph[cur].nxt != 0) {
                res[c].tap = graph[cur].nxt;
                if (res[c].dia > graph[cur].nwt)
                    res[c].dia = graph[cur].nwt;
                cur = graph[cur].nxt;
            }
            if (res[c].tap == 0)
                continue;
            c++;
        }
    }
    printf("%d\n", c);
    sort(res, res+c, cmp);
    for (int i = 0; i < c; i++)
        printf("%d %d %d\n", res[i].tank, res[i].tap, res[i].dia);
    return 0;
}
