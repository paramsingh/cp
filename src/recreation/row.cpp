#include <bits/stdc++.h>
using namespace std;


char a[10100];

int main(void) {
    int n;
    scanf("%d", &n);
    scanf("%s", a + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == '0') {
            int l = (i == 1) || (a[i - 1] == '0');
            int r = (i == n) || (a[i + 1] == '0');
            if (l && r) {
                printf("No\n");
                return 0;
            }
        }
        else {
            if (a[i - 1] == '1' || a[i + 1] == '1') {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
