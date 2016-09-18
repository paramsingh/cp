#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char *s = (char*) calloc(n+10, sizeof(char));
        scanf("%s", s);
        int r = 0, g = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R')
                r++;
            else if (s[i] == 'G')
                g++;
            else if (s[i] == 'B')
                b++;
        }
        int ans = max(max(r, g), b);
        ans = n - ans;
        printf("%d\n", ans);
        free(s);
    }
    return 0;
}
