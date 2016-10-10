#include <bits/stdc++.h>
using namespace std;

int lucky(int n) {
    while (n > 0) {
        if (n % 10 != 4 && n % 10 != 7)
            return 0;
        n = n / 10;
    }
    return 1;
}


int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && lucky(i)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
