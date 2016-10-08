#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

set<char> mp;
char s[100100];

int main(void) {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        mp.insert(s[i]);
    }
    if ((int)mp.size() % 2 == 0)
        printf("CHAT WITH HER!\n");
    else
        printf("IGNORE HIM!\n");
    return 0;
}
