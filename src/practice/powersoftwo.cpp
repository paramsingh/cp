#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int a[100100];
int n;
int main(void) {
    unordered_map<lli, int> mp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mp[a[0]] = 1;
    lli ans = 0;
    for (int i = 1; i < n; i++) {
        for (int p = 0; p < 40; p++) {
            lli num = (1LL) << p;
            lli x = num - a[i];
            int c = mp[x];
            ans += c;
        }
        if (mp.count(a[i]))
            mp[a[i]]++;
        else
            mp[a[i]] = 1;
    }
    cout << ans << endl;
    return 0;
}
