#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int y;
    scanf("%d", &y);
    int leap = (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
    int d = 0;
    for (int i = y + 1; ; i++) {
        int flag = (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
        if (flag)
            d = (d + 2) % 7;
        else
            d = (d + 1) % 7;
        if (d == 0) {
            if (leap && flag) {
                printf("%d\n", i);
                break;
            }
            else if (!leap && !flag) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
