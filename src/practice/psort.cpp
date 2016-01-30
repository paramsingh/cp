// http://codeforces.com/problemset/problem/28/B

#include <bits/stdc++.h>
using namespace std;

int adj[200][200] = {0};

int main(void) {
    int n;
    scanf("%d", &n);
    int i, j, k;
    int fin[n+1];
    int fav[n+1];
    for (i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        fin[x] = i;
    }
    for (i = 1; i <= n; i++)
        scanf("%d", fav+i);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j || abs(i-j) == fav[i]) {
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }
    for (i = 1; i <= n; i++) {
        if (adj[i][fin[i]] == 0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
