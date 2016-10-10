#include <bits/stdc++.h>
using namespace std;

char hello[10] = "hello";
char s[1000];

int main(void) {
    scanf("%s", s);
    int l = strlen(s);
    int nxt = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == hello[nxt]) {
            nxt++;
            if (nxt == 5) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
