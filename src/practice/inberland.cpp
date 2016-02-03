// http://codeforces.com/problemset/problem/25/C

#include <bits/stdc++.h>
using namespace std;

long long int d[310][310];
long long int d2[310][310];
int n;

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> d[i][j];
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        int a = u, b = v;
        long long int sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d2[i][j] = d[i][j];
                if (d2[i][j] > d[i][a] + w + d[b][j])
                    d2[i][j] = d[i][a] + w + d[b][j];
                if (d2[i][j] > d[i][b] + w + d[a][j])
                    d2[i][j] = d[i][b] + w + d[a][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = d2[i][j];
                if (j >= i)
                    sum += d[i][j];
            }
        }
        cout << sum << " ";
    }
    printf("\n");
    return 0;
}
