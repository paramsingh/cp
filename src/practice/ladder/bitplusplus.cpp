#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, x = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[5];
        scanf("%s", s);
        if (s[1] == '+')
            x++;
        else
            x--;
    }
    printf("%d\n", x);
}
