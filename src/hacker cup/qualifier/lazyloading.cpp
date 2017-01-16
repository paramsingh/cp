#include <bits/stdc++.h>
using namespace std;

int a[200];

int main(void) {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int nxt = 1;
        int ans = 0;
        for (int i = n; i >= nxt; i--) {
            int total = a[i];
            while (total < 50 && nxt < i) {
                total += a[i];
                nxt++;
            }
            if (total >= 50)
                ans++;
        }
        printf("Case #%d: %d\n", test, ans);
    }
}
