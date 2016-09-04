// Gaussian Elimination
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int length(ull n) {
    int cnt = 0;
    while (n > 0) {
        n >>= 1;
        cnt++;
    }
    return cnt;
}

ull a[100100];
ull reduced[100100];
vector<ull> buckets[100];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%llu", a+i);
        int l = length(a[i]);
        buckets[l].push_back(a[i]);
    }
    int cnt = 0;
    for (int i = 64; i > 0; i--) {
        if (!buckets[i].empty()) {
            ull pivot = buckets[i][0];
            reduced[cnt++] = pivot;
            for (int j = 1; j < buckets[i].size(); j++) {
                ull x = buckets[i][j] ^ pivot;
                int l = length(x);
                buckets[l].push_back(x);
            }
            buckets[i].clear();
        }
    }


    ull ans = 0;
    for (int i = 0; i < cnt; i++) {
        if (ans < (reduced[i] ^ ans)) {
            ans = ans ^ reduced[i];
        }
    }
    printf("%llu\n", ans);
    return 0;
}
