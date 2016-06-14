#include <bits/stdc++.h>
using namespace std;

int arr[1000100];

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);
    int oo = 0, eo = 0;
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int ch;
            scanf("%d", &ch);
            oo += ch;
            eo += ch;
        }
        else {
            int pos0 = eo % n;
            if (pos0 < 0)
                pos0 += n;
            if (pos0 % 2 == 0) {
                eo++;
                oo--;
            }
            else {
                eo--;
                oo++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int pos;
        if (i % 2 == 0) {
            pos = (i + eo) % n;
        }
        else {
            pos = (i + oo) % n;
        }
        if (pos < 0)
            pos += n;
        arr[pos] = i+1;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}


