#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ll n, k;
    cin >> n >> k;
    ll even = n / 2;
    ll odd = n - even;
    if (odd >= k) {
        cout << 2 * (k - 1) + 1 << endl;
    }
    else {
        ll req = k - odd;
        cout << 2 * req << endl;
    }
    return 0;
}
