#include <bits/stdc++.h>
using namespace std;

char a[1000100];
char b[1000100];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", a);
        scanf("%s", b);
        int n = strlen(a);
        int c0 = 0, c1 = 0, w0 = 0, w1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                if (a[i] == '0')
                    c0++;
                else
                    c1++;
            }
            else {
                if (a[i] == '0')
                    w0++;
                else
                    w1++;
            }
        }

        // w0 contains number of zeros to change
        // w1 contains number of ones to change
        int ops = min(w0, w1);
        c0 += ops;
        c1 += ops;
        w0 -= ops;
        w1 -= ops;

        int cant = 0;
        if (w0 > 0) {
            if (c1 > 0) {
                ops += w0;
            }
            else
                cant = 1;
        }

        if (w1 > 0) {
            if (c0 > 0)
                ops += w1;
            else
                cant = 1;
        }

        if (cant)
            printf("Unlucky Chef\n");
        else {
            printf("Lucky Chef\n");
            printf("%d\n", ops);
        }
    }
    return 0;
}

