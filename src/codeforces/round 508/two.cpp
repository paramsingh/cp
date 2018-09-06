#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 1e9 + 8;
const ll infll = 1e18;



int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 1 || n == 2)  {
        printf("No\n");
        return 0;
    }
    else {
        printf("Yes\n");
        printf("1 %d\n", n);
        printf("%d ", n - 1);
        for (int i = 1; i < n; i++)
            printf("%d ", i);
        printf("\n");
        return 0;
    }
}

