#include <bits/stdc++.h>
using namespace std;

char s[100100];
int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long int k;
        scanf("%lld", &k);
        k--;
        int l = 0;
        if (k == 0)
            s[l++] = '0';
        while (k != 0) {
            int digit = k % 5;
            s[l++] = digit * 2 + '0';
            k /= 5;
        }
        for (int i = l - 1; i >= 0; i--)
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}

