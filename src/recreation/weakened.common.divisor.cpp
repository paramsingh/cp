#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> get(ll a) {
    vector<int> ans;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            ans.push_back(i);
            while (a % i == 0)
                a /= i;
        }
    }
    if (a > 1) ans.push_back(a);
    return ans;
}


int n;
ll a[200100], b[200100];

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
    }
    vector<int> one = get(a[1]);
    vector<int> two = get(b[1]);
    for (int x: one) {
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % x == 0 || b[i] % x == 0)
                c++;
        }
        if (c == n) {
            printf("%d\n", x);
            return 0;
        }
    }
    for (int x: two) {
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % x == 0 || b[i] % x == 0)
                c++;
        }
        if (c == n) {
            printf("%d\n", x);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}


