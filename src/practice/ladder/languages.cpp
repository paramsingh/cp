#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

set<int> graph[200];
int knows[110][110];
int visited[110];
int knowcnt[110];
int n, m;

void dfs(int u) {
    visited[u] = 1;
    for (int v: graph[u]) {
        if (visited[v] == 0)
            dfs(v);
    }
}

int main(void) {
    int x, flag = 0;
    scanf("%d %d", &n, &m);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", knowcnt + i);
        if (knowcnt[i] > 0)
            flag = 1;
        for (int j = 1; j <= knowcnt[i]; j++) {
            scanf("%d", &x);
            knows[i][x] = 1;
            for (int k = 1; k < i; k++) {
                if (knows[k][x]) {
                    graph[k].insert(i);
                    graph[i].insert(k);
                }
            }
        }
    }

    if (flag == 0) {
        printf("%d\n", n);
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt - 1 << endl;
    return 0;
}
