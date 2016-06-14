#include <bits/stdc++.h>
using namespace std;

int a[500100];
int n, k;

int main(void) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    int steps = 0;
    while (true) {
        int mn = a[0], mni = 0, mx = a[0], mxi = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < mn) {
                mn = a[i];
                mni = i;
            }
            if (a[i] > mx) {
                mx = a[i];
                mxi = i;
            }
        }
        if (mn == mx)
            break;
        else {
            steps++;
            a[mni]++;
            a[mxi]--;
            printf("step %d: ", steps);
            for (int i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");
        }
    }
    return 0;
}


