#include <bits/stdc++.h>
using namespace std;

int a[100100];
int b[100100];
int c[100100];
int sa[100100];
int sb[100100];
int sc[100100];

int main(void) {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    for (int i = 1; i <= n1; i++)
        scanf("%d", a+i);
    for (int i = 1; i <= n2; i++)
        scanf("%d", b+i);
    for (int i = 1; i <= n3; i++)
        scanf("%d", c + i);

    for (int i = n1; i >= 1; i--)
        sa[i] = sa[i+1] + a[i];
    for (int i = n2; i >= 1; i--)
        sb[i] = sb[i+1] + b[i];
    for (int i = n3; i >= 1; i--)
        sc[i] = sc[i+1] + c[i];

    for (int i = 1; i <= n1; i++) {
        int val = sa[i];
        int lo = 1, hi = n2;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (sb[mid] > val)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (sb[lo] != val)
            continue;

        lo = 1, hi = n3;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (sc[mid] > val)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (sc[lo] != val)
            continue;

        printf("%d\n", val);
        return 0;
    }
    printf("0\n");
    return 0;
}
