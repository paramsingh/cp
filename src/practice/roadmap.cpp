// http://codeforces.com/problemset/problem/34/D

#include <bits/stdc++.h>
using namespace std;

vector<int> tree[50010];
int ans[50010];
int visited[50010] = {0};

void dfs(int cur, int prev) {
    visited[cur] = 1;
    ans[cur] = prev;
    int i;
    for (i = 0; i < tree[cur].size(); i++) {
        int v = tree[cur][i];
        if (v != prev)
            dfs(v, cur);
    }
}

int main(void) {
    int n, prev, now;
    scanf("%d %d %d", &n, &prev, &now);
    int i, pr;
    for (i = 1; i <= n; i++) {
        if (i != prev) {
            scanf("%d", &pr);
            tree[pr].push_back(i);
            tree[i].push_back(pr);
        }
    }
    dfs(now, -1);
    for (i = 1; i <= n; i++) {
        if (i != now)
            printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
