#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int sum[5];

int main(void) {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        for (int i = 1; i <= 3; i++) {
            scanf("%d", &x);
            sum[i] += x;
        }
    }
    printf("%s\n", sum[1] == 0 && sum[2] == 0 && sum[3] == 0 ? "YES" : "NO");
    return 0;
}
