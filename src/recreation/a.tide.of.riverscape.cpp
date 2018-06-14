#include <bits/stdc++.h>
using namespace std;

char s[10100];


int main(void) {
    int n, p;
    scanf("%d %d", &n, &p);
    scanf("%s", s + 1);
    int cnt = 0;
    for (int i = 1; i <= n - p; i++) {
        if (s[i] == '.' && s[i + p] == '.') {
            s[i] = '1';
            s[i + p] = '0';
            cnt += 1;
        }
        else if (s[i] == '.') {
            s[i] = s[i + p] == '0' ? '1': '0';
            cnt += 1;
        }
        else if (s[i + p] == '.') {
            s[i + p] = s[i] == '0' ? '1': '0';
            cnt += 1;
        }
        else {
            if (s[i] != s[i + p]) {
                cnt += 1;
            }
        }
    }
    for (int i = n - p + 1; i <= n; i++) {
        if (s[i] == '.')
            s[i] = '0';
    }
    if (cnt > 0)
        printf("%s\n", s + 1);
    else
        printf("NO\n");
}
