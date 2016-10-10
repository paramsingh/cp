#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    int cnt = 0;
    scanf("%d %d", &n, &m);
    for (int a = 0; a <= 1000; a++) {
        for (int b = 0; b <= 1000; b++) {
            int one = a * a + b;
            int two = a + b * b;
            if (one == n && two == m)
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
