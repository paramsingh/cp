#include <bits/stdc++.h>
using namespace std;

char s[10010];
char s2[10010];
int n, cx;
int cnt, total;

void get(int x, int here) {
    if (here == n) {
        if (x == cx)
            cnt++;
        total++;
    }
    else {
        if (s2[here] == '?') {
            get(x + 1, here + 1);
            get(x - 1, here + 1);
        }
        else if (s2[here] == '+')
            get(x + 1, here + 1);
        else
            get(x - 1, here + 1);
    }
}

int main(void) {
    scanf("%s", s);
    scanf("%s", s2);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '+')
            cx++;
        else
            cx--;
    }
    get(0, 0);
    printf("%.15lf\n", cnt / (double) total);
    return 0;
}
