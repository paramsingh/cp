#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull p = 1e9 + 7;
int a[200100], b[200100];
int da[200100], db[200100];
int n, w;
int lps[200100];
int l;

void preprocess() {
    lps[0] = 0;
    int len = 0;
    for (int i = 1; i < l; ) {
        if (db[i] == db[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                // aaacaaaa
                // 01201233
                len = lps[len - 1];

            }
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &w);
    if (w == 1) {
        printf("%d\n", n);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i) da[i - 1] = a[i] - a[i - 1];
    }
    for (int i = 0; i < w; i++) {
        scanf("%d", &b[i]);
        if (i) db[i - 1] = b[i] - b[i - 1];
    }
    l = w - 1;
    preprocess();
    int i = 0, j = 0; // i for da, j for db
    int cnt = 0;
    while (i < n -1) { // length of text is n - 1
        if (da[i] == db[j]) {
            i++;j++;
        }
        if (j == l) {
            cnt++;
            j = lps[j - 1];
        }
        else if (i < n - 1 && da[i] != db[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    printf("%d\n", cnt);
}
