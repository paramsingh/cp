// http://codeforces.com/problemset/problem/232/A

#include <bits/stdc++.h>
using namespace std;

int a[110][110] = {0};
int order[110] = {0};
int n;
int k;
bool check() {
    int c = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (a[i][k] && a[k][j] && a[j][i]) {
                    c++;
                }
            }
        }
    }
    printf("%d\n", c);
}
int main(void) {
    scanf("%d", &k);
    // for first cycle
    a[1][2] = 1;
    a[2][1] = 1;
    a[1][3] = 1;
    a[3][1] = 1;
    a[2][3] = 1;
    a[3][2] = 1;
    n = 3;
    k--;
    while (k > 0) {
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j != i && !a[i][j]) {
                    int count = 0;
                    for (int u = 1; u <= n; u++) {
                        if (a[i][u] == 1 && a[j][u] == 1)
                            count++;
                    }
                    if (k - count >= 0) {
                        k -= count;
                        a[i][j] = 1;
                        a[j][i] = 1;
                        flag = 1;
                    }
                }
            }
        }
        if (flag == 0) {
            n++;
            a[1][n] = 1;
            a[n][1] = 1;
            a[2][n] = 1;
            a[n][2] = 1;
            k--;
        }
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
