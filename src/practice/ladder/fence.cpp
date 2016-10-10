#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int a[200100];
int pref[200100];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        pref[i] = pref[i - 1] + a[i];
    }
    int ans = inf, ansid = -1;
    for (int i = 1; i + k - 1 <= n; i++) {
        if (ans > pref[i + k - 1] - pref[i - 1]) {
            ans = pref[i + k - 1] - pref[i - 1];
            ansid = i;
        }
    }
    cout << ansid << endl;
    return 0;
}
