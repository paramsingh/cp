#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
const int mod = 1e9 + 7;

int freq[500100];
int a[100100];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }
    int ans = 1;
    for (int g = 2; g <= 1e5; g++) {
        int cnt = 0;
        for (int x = g; x <= 1e5; x+=g)
            cnt += freq[x];
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
