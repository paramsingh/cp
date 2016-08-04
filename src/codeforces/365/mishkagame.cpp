#include <bits/stdc++.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int w = 0, l = 0, t = 0;
    for (int i = 0; i < n; i++) {
        int m, c;
        scanf("%d %d", &m, &c);
        if (m > c)
            w++;
        else if (m < c)
            l++;
        else
            t++;
    }
    if (w > l)
        printf("Mishka\n");
    else if (l > w)
        printf("Chris\n");
    else
        printf("Friendship is magic!^^\n");
    return 0;
}
