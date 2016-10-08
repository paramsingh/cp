#include <bits/stdc++.h>
using namespace std;
char s[110];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        int l = strlen(s);
        if (l <= 10)
            printf("%s\n", s);
        else
            printf("%c%d%c\n", s[0], l - 2, s[l - 1]);
    }
    return 0;
}
