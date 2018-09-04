// 22:47
//
#include <bits/stdc++.h>
using namespace std;


int n;
char a[1001000], b[1001000];


int main(void) {
    scanf("%d", &n);
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            if (i < n && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) {
                ans++;
                a[i] = b[i];
                a[i + 1] = b[i + 1];
            }
            else {
                ans++;
                a[i] = b[i];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
