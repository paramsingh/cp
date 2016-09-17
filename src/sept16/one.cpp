#include <bits/stdc++.h>
using namespace std;

char s[100100];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int l = strlen(s);
        int one = 0, zero = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == '0')
                zero++;
            if (s[i] == '1')
                one++;
        }
        if (zero == 1 || one == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
