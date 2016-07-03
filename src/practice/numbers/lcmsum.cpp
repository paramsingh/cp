#include <bits/stdc++.h>
using namespace std;

int phi[1000100];
int sieve[1000100];
vector<int> factors;
vector<int> mul;
long long a;

void ans(int i, long long pr) {
    if (i == factors.size())
        a += pr * phi[pr];
    else {
        for (int x = 0; x <= mul[i]; x++) {
            ans(i + 1, pr);
            pr *= factors[i];
        }
    }
}

int main(void) {
    phi[1] = 1;
    sieve[0] = sieve[1] = 1;
    for (int i = 2; i < 1000100; i++)
        phi[i] = i;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j <= 1000000; j += i) {
                sieve[j] = i;
                phi[j] -= phi[j] / i;
            }
        }
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int x = n;
        while (x != 1) {
            int s = factors.size() - 1;
            if (factors.empty() || factors[s] != sieve[x]) {
                factors.push_back(sieve[x]);
                mul.push_back(1);
            }
            else
                mul[s]++;
            x /= sieve[x];
        }
        a = 0;
        ans(0, 1);
        a = ((a - 1) * n) / 2 + n;
        printf("%lld\n", a);
        factors.clear();
        mul.clear();
    }
    return 0;
}

