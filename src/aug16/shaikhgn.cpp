#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n, m;
struct matrix {
    ull matr[510][10];
    ull matc[10][510];
    matrix() {
        memset(matr, 0, sizeof(matr));
        memset(matc, 0, sizeof(matc));
    }

    matrix operator*(const matrix& a) {
        matrix pr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    ull x = matr[i][k] & a.matc[k][j];
                    if (x > 0) {
                        // update in row matrix
                        pr.matr[i][j >> 6] |= (((ull)1) << (j & 63));
                        // update in column matrix
                        pr.matc[i >> 6][j] |= (((ull)1) << (i & 63));
                        break;
                    }

                }
            }
        }
        return pr;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int bit = (matc[i >> 6][j] >> (i & 63)) & 1;
                printf("%d ", bit);
            }
            printf("\n");
        }
    }

    void printboth() {
        printf("row\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf("%llu ", matr[i][j]);
            printf("\n");
        }

        printf("column\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                printf("%llu ", matc[i][j]);
            printf("\n");
        }
    }
};

matrix powers[40];
ull row[10];
ull p[10];

void printrow() {
    printf("row now\n");
    for (int i = 0; i < n; i++) {
        if ((row[i >> 6] >> (i & 63)) & 1) {
            printf("%d\n", i + 1);
        }
    }
    printf("\n");
}


int main(void) {
    scanf("%d", &n);
    m = ceil(n / 64.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if (x == 1) {
                powers[0].matr[i][j >> 6] |= (((ull)1) << (j & 63));
                powers[0].matc[i >> 6][j] |= (((ull)1) << (i & 63));
            }
        }
    }
    for (int i = 1; i <= 30; i++)
        powers[i] = powers[i-1] * powers[i-1];
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(row, 0, sizeof(row));
        int k, x;
        scanf("%d %d", &k, &x);
        x--;
        row[x >> 6] |= (((ull)1) << (x & 63));
        int cnt = 0;
        while (k > 0) {
            if (k & 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        ull x = row[j] & powers[cnt].matc[j][i];
                        if (x > 0) {
                            p[i >> 6] |= (((ull)1) << (i & 63));
                            break;
                        }
                    }
                }
                for (int i = 0; i < m; i++) {
                    row[i] = p[i];
                    p[i] = 0;
                }
            }
            k >>= 1;
            cnt++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((row[i >> 6] >> (i & 63)) & 1)
                ans.push_back(i + 1);
        }
        printf("%d\n", (int)ans.size());
        if (!ans.empty()) {
            for (int i = 0; i < ans.size(); i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
        else
            printf("-1\n");
    }

    return 0;
}
