#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    int confirm = (n / 7) * 2;
    int rem = n % 7;
    if (rem == 6)
        printf("%d %d\n", confirm + 1, confirm + 2);
    else if (rem >= 2)
        printf("%d %d\n", confirm, confirm + 2);
    else if (rem >= 1)
        printf("%d %d\n", confirm, confirm + 1);
    else if (rem == 0)
        printf("%d %d\n", confirm, confirm);
    return 0;
}
