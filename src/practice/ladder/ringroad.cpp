#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a[100100];

int dist(int x, int y) {
    if (x <= y)
        return y - x;
    else
        return n + y - x;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", a + i);
    int house = 1;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dist(house, a[i]);
        house = a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
