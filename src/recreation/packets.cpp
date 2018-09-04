#include <bits/stdc++.h>
using namespace std;


int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 31; i >= 0; i--) {
        if ((n >> i) & 1) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
}
