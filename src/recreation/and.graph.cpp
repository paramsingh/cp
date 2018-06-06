#include <bits/stdc++.h>
using namespace std;


int done[2][(1 << 22) + 10];
int here[(1 << 22) + 10];
int a[(1 << 22) + 10];
int n, m;

void dfs(int val, int type) {
    if (done[type][val]) return;
    done[type][val] = 1;
    if (type == 0) {
        dfs(val, 1);
    }
    else {
        for (int i = 0; i < n; i++) {
            if ((val >> i) & 1)
                continue;
            else
                dfs(val | (1 << i), 1);
        }
        int inverse = (1 << n) - 1 - val;
        if (here[inverse])
            dfs(inverse, 0);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
        here[a[i]] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (done[0][a[i]]) continue;
        cnt += 1;
        dfs(a[i], 0);
    }
    printf("%d\n", cnt);
    return 0;
}

