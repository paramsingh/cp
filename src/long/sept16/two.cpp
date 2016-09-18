#include <bits/stdc++.h>
using namespace std;

char s[100100];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int l = strlen(s);
        int flag = 1;
        for (int i = 0; i < l; i++) {
            int j = l - 1 - i;
            if (s[i] == s[j] && s[i] == '.')
                s[i] = s[j] = 'a';
            else if (s[i] == '.' && s[i] != s[j])
                s[i] = s[j];
            else if (s[j] == '.' && s[i] != s[j])
                s[j] = s[i];
            else if (s[i] != '.' && s[i] != s[j])
                flag = 0;
        }
        if (flag)
            printf("%s\n", s);
        else
            printf("-1\n");
    }
    return 0;
}
