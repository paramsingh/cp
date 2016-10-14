#include <bits/stdc++.h>
using namespace std;

char s1[1001000], s2[1001000];
int main(void) {
    scanf("%s", s1);
    scanf("%s", s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    if (l1 != l2) {
        printf("NO\n");
        return 0;
    }
    int one1 = 0, one2 = 0;
    for (int i = 0; i < l1; i++)
        one1 += s1[i] == '1';
    for (int i = 0; i < l2; i++)
        one2 += s2[i] == '1';
    printf("%s\n", (one1 == 0 && one2 == 0) || (one2 > 0 && one1 > 0) ? "YES" : "NO");
    return 0;
}
