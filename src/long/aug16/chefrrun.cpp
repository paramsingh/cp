#include <bits/stdc++.h>
using namespace std;

int done[100100];
int depth[100100];
int a[100100];
int n;
int cmp;
int ans;

void dfs(int u, int d) {
    done[u] = cmp;
    depth[u] = d;
    int nxt = (u + a[u] + 1) % n;
    if (done[nxt] == 0)
        dfs(nxt, d + 1);
    else if (done[nxt] != cmp)
        return;
    else
        ans += d - depth[nxt] + 1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
            done[i] = 0;
        }
        ans = 0;
        cmp = 0;
        for (int i = 0; i < n; i++) {
            if (done[i] == 0) {
                cmp++;
                dfs(i, 0);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
