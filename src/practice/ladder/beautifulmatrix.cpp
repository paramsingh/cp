#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            scanf("%d", &x);
            if (x == 1) {
                int ans = abs(i - 2) + abs(j - 2);
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    return 0;
}
