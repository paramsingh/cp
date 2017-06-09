#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


char s[100100];

int a[100100][2];
int b[100100][2];

int main(void) {
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    ll odd = 0, even = 0;
    for (int i = 1; i <= l; i++) {
        if (s[i] == 'a')
            a[i][i % 2] += 1;
        else
            b[i][i % 2] += 1;

        a[i][0] += a[i - 1][0];
        a[i][1] += a[i - 1][1];
        b[i][0] += b[i - 1][0];
        b[i][1] += b[i - 1][1];

        if (s[i] == 'a') {
            odd  += a[i][i % 2];
            even += a[i][!(i % 2)];
        }
        else {
            odd +=  b[i][i % 2];
            even += b[i][!(i % 2)];
        }
    }
    printf("%lld %lld\n", even, odd);
}
