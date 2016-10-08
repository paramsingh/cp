#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int main(void) {
    int n, x;
    scanf("%d", &n);
    int prev = -1, cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        x = x == 10 ? 0 : 1;
        if (prev == -1 || x != prev)
            cnt++;
        prev = x;
    }
    printf("%d\n", cnt);
    return 0;
}
