#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct edge {
    int u, v, w;
    edge(int a, int b, int c) {
        u = a, v = b, w = c;
    }
};
vector<edge> edges;
vector<int> cuts;

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int s, t;
    scanf("%d %d", &s, &t);
    s--, t--;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        edges.push_back(edge(u, v, w));
    }
    for (int i = 0; i < (1 << n); i++) {
        if (((i >> s) & 1) == 0)
            continue;
        if ((i >> t) & 1)
            continue;
        int ans = 0;
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (((i >> u) & 1) == 0) continue;
            if ((i >> v) & 1) continue;
            ans += w;
        }
        cuts.push_back(ans);
    }
    sort(cuts.begin(), cuts.end());
    printf("%d\n", cuts[k - 1]);
    return 0;
}
