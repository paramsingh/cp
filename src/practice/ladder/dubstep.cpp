#include <bits/stdc++.h>
using namespace std;

char s[210];

char wub[5] = "WUB";

string ans;

int main(void) {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; )  {
        int flag = 1;
        for (int cnt = 0; cnt < 3; cnt++) {
            if (i + cnt >= l || s[i + cnt] != wub[cnt])
                flag = 0;
        }
        if (flag == 0) {
            ans += s[i];
            i++;
        }
        else {
            ans += ' ';
            i += 3;
        }
    }
    int lead = 1;
    for (int i = 0; i < ans.length();) {
        char ch = ans[i];
        while (lead && ans[i] == ' ')
            i++;
        lead = 0;
        if (ans[i] == ' ') {
            printf(" ");
            while (ans[i] == ' ')
                i++;
        }
        else {
            printf("%c", ans[i]);
            i++;
        }
    }
    return 0;
}
