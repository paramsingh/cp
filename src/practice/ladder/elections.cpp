#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> graph[100100];
int dp[100100];
int cntbad[100100];

void dfs1(int u, int p = -1, int cnt = 0) {
    dp[u] = cnt;
    cntbad[u] = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, bad = graph[u][i].second;
        if (v != p) {
            dfs1(v, u, bad ? cnt + 1 : cnt);
            if (bad) cntbad[u]++;
            cntbad[u] += cntbad[v];
        }
    }
}

vector<int> ans;

void dfs2(int u, int p = -1, int pbad = 0) {
    int baddown = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, bad = graph[u][i].second;
        if (v != p) {
            if (bad) {
                baddown = 1;
                dfs2(v, u, 1);
            }
            else if (cntbad[v] > 0) {
                baddown = 1;
                dfs2(v, u, 0);
            }
        }
    }
    if (baddown == 0 && pbad == 1)
        ans.push_back(u);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int bad = 0;
    for (int i = 1; i < n; i++) {
        int u, v, p;
        scanf("%d %d %d", &u, &v, &p);
        p = (p == 2) ? 1 : 0;
        if (p) bad++;
        graph[u].push_back(make_pair(v, p));
        graph[v].push_back(make_pair(u, p));
    }

    // no bad edges
    if (bad == 0) {
        printf("0\n");
        return 0;
    }

    dfs1(1);
    dfs2(1);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
