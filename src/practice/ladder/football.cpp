#include <bits/stdc++.h>
using namespace std;

char s[110];

int main(void) {
    scanf("%s", s);
    int l = strlen(s);
    int mx = 0;
    for (int i = 0; i < l; ) {
        char ch = s[i];
        int cnt = 0;
        while (i < l && s[i] == ch) {
            cnt++;
            i++;
        }
        mx = max(cnt, mx);
    }
    printf("%s\n", mx >= 7 ? "YES" : "NO");
    return 0;
}
