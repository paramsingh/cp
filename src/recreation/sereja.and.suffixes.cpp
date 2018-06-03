#include <bits/stdc++.h>
using namespace std;

int a[100100];
int freq[100100];
int l[100100];
int ans[100100];
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) 
        scanf("%d", &l[i]);
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (freq[a[i]] == 0) {
            cnt += 1;
            freq[a[i]] = 1;
        }
        ans[i] = cnt;
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[l[i]]);
    }
}


