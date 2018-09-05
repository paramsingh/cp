#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 1e9 + 8;
const ll infll = 1e18;


int c[10010];

int main(void) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] != 2 && c[n - i + 1] != 2 && c[i] != c[n - i +1]) {
            printf("-1\n");
            return 0;
        }
        if (c[i] == 2) {
            if (c[n - i + 1] == 2) {
                ans += min(a, b);
                if (n - i + 1 != i)
                    ans += min(a, b);
                c[i] = c[n - i + 1] = 1;
            }
            else if (c[n - i + 1] == 1) {
                ans += b;
                c[i] = 1;
            }
            else {
                ans += a;
                c[i] = 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

