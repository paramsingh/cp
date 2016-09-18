#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        if (a == 1 && b == 2)
            printf("Yes");
        else if (a == 2 && b == 1)
            printf("Yes");
        else if (a == 1 || b == 1)
            printf("No");
        else if (a == 2 || b == 2)
            printf("Yes");
        else if (a % 2 == 0 || b % 2 == 0)
            printf("Yes");
        else
            printf("No");
        printf("\n");
    }
    return 0;
}
