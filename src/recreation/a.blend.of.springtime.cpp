#include <bits/stdc++.h>
using namespace std;

char s[1001];


int main(void) {
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for (int i = 1; i <= l; i++) {
        int a[3];
        a[0] = a[1] = a[2] = 0;
        for (int x = i - 1; x <= i + 1; x++) {
            if (s[x] == 'A' || s[x] == 'B' || s[x] == 'C')
                a[s[x] - 'A']++;
        }
        if (a[0] > 0 && a[1] > 0 && a[2] > 0) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
