#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 1e9 + 8;
const ll infll = 1e18;


int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int once = 2 * k + 1;
    vector<int> ans;
    int start = 1, end = n;
    int rem = n;
    if (n % once != 0) {
        int extra = n % once;
        int left = extra - (k + 1);
        if (left > 0)
            start += left;
        ans.push_back(start);
        rem -= extra;
        start += k + 1;
    }
    int cur = start + k;
    while (rem > 0 && cur <= n) {
        ans.push_back(cur);
        cur += k + k + 1;
        rem -= once;
    }
    printf("%d\n",(int) ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}

