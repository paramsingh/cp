#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 1e9 + 8;
const ll infll = 1e18;


char s[100100];
int freq[30];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }
    int mn = n + 1;
    for (int i = 0; i < k; i++) {
        mn = min(mn, freq[i]);
    }
    printf("%d\n", k * mn);
    return 0;
}

