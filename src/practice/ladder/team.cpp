#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int main(void) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a + b + c >= 2)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
