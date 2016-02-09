// http://www.spoj.com/problems/DIVFACT/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int seive[50010] = {0};
int cnt[50010] = {0};

class query {
    public:
        int i;
        int n;
} queries[510];

int ans[510];

bool cmp(const query& a, const query& b) {
    return a.n < b.n;
}

int main(void) {
    for (int i = 2; i <= 50000; i++) {
        if (seive[i] == 0) {
            for (int j = i; j <= 50000; j+=i)
                seive[j] = i;
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &queries[i].n);
        queries[i].i = i;
    }
    sort(queries, queries + t, cmp);
    int prev = 2;
    for (int i = 0; i < t; i++) {
        int n = queries[i].n;
        for (int j = prev; j <= n; j++) {
            int cur = j;
            while (cur != 1) {
                cnt[seive[cur]]++;
                cur /= seive[cur];
            }
        }
        long long int sum = 1;
        for (int j = 2; j <= n; j++) {
            sum = (sum * (cnt[j]+1) % MOD) % MOD;
        }
        ans[queries[i].i] = sum;
        prev = n + 1;
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", ans[i]);
    return 0;
}

