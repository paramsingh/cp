#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
const int mod = 1e9 + 7;

char s[100100];
map<char, int> mp;

int main(void) {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; i++)
        mp[s[i]]++;
    // Bulbasaur
    int ans = min(mp['B'], mp['u'] / 2);
    ans = min(ans, mp['l']);
    ans = min(ans, mp['b']);
    ans = min(ans, mp['a'] / 2);
    ans = min(ans, mp['s']);
    ans = min(ans, mp['r']);
    printf("%d\n", ans);
    return 0;
}
