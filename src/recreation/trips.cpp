#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > graph[200100];
set<pair<int, int> > good;
pair<int, int> edges[200100];

int degree[200100];

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[i] = make_pair(u, v);
        graph[u].push_back(make_pair(v, i));
        graph[v].push_back(make_pair(u, i));
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= n; i++) {
        good.insert(make_pair(degree[i], i));
    }
    while (true) {
        if (good.empty()) break;
        pair<int, int> p = *(good.begin());
        int u = p.second, uk = p.first;
        if (uk >= k) break;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            if (good.count(make_pair(degree[v], v))) {
                good.erase(make_pair(degree[v], v));
                degree[v]--;
                good.insert(make_pair(degree[v], v));
            }
        }
        good.erase(make_pair(uk, u));
    }
    vector<int> ans;
    for (int edge = m; edge >= 1; edge--) {
        ans.push_back((int) good.size());
        int u = edges[edge].first, v = edges[edge].second;
        if (good.count(make_pair(degree[u], u)) && good.count(make_pair(degree[v], v))) {
            good.erase(make_pair(degree[u], u));
            degree[u]--;
            good.insert(make_pair(degree[u], u));

            good.erase(make_pair(degree[v], v));
            degree[v]--;
            good.insert(make_pair(degree[v], v));


            while (true) {
                if (good.empty()) break;
                pair<int, int> p = *(good.begin());
                int u = p.second, uk = p.first;
                if (uk >= k) break;
                for (int i = 0; i < graph[u].size(); i++) {
                    int v = graph[u][i].first;
                    if (graph[u][i].second >= edge) continue;
                    if (good.count(make_pair(degree[v], v))) {
                        good.erase(make_pair(degree[v], v));
                        degree[v]--;
                        good.insert(make_pair(degree[v], v));
                    }
                }
                good.erase(make_pair(uk, u));
            }
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        printf("%d\n", ans[i]);
    return 0;
}
