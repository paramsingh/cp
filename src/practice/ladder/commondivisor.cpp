#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull p = 31;

ull powers[100100];
char s1[100100], s2[100100];
ull h1[100100], h2[100100];
int l1, l2;

int main(void) {
    powers[0] = 1;
    for (int i = 1; i <= 100010; i++)
        powers[i] = powers[i - 1] * p;
    scanf("%s", s1);
    scanf("%s", s2);
    l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i < l1; i++) {
        h1[i] = powers[i] * (s1[i] - 'a' + 1);
        if (i) h1[i] += h1[i - 1];
    }

    for (int i = 0; i < l2; i++) {
        h2[i] = powers[i] * (s2[i] - 'a' + 1);
        if (i) h2[i] += h2[i - 1];
    }

    int cnt = 0;
    for (int i = 0; i < l1; i++) {
        int l = i + 1;
        if (l1 % l == 0 && l2 % l == 0) {
            int flag = 1;
            for (int st = 0; st + l - 1 < l1; st += l) {
                ull h = h1[st + l - 1] - (st == 0 ? 0 : h1[st - 1]);
                if (h1[i] * powers[st] != h) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                continue;
            for (int st = 0; st + l - 1 < l2; st += l) {
                ull h = h2[st + l - 1] - (st == 0 ? 0 : h2[st - 1]);
                if (h1[i] * powers[st] != h) {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                cnt++;
        }
    }
    printf("%d\n", cnt);
}
