#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

long long int id[100100];

int main(void) {
    long long int n;
    long long int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        scanf("%lld", id+i);
    lli val;
    for (lli i = 1; i <= n; i++)
        if (k <= (i * (i + 1) / 2)) {
            val = i;
            break;
        }
    k -= (val - 1) * val / 2;
    cout << id[k] << endl;
    return 0;
}

