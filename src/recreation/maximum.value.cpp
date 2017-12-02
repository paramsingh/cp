#include <bits/stdc++.h>
using namespace std;


int have[2001000];
int largest[2001000];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        have[x] = 1;
    }
    for (int i = 1; i <= 2e6; i++) {
        if (have[i - 1])
            largest[i] = i - 1;
        else
            largest[i] = largest[i - 1];
    }
    int ans = 0;
    for (int aj = 1; aj <= 1e6; aj++) {
        if (!have[aj]) continue;

        for (int i = 2; i * aj <= 2e6; i++)
            ans = max(ans, largest[i * aj] % aj);
    }

    printf("%d\n", ans);
    return 0;
}
