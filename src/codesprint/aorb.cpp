#include <bits/stdc++.h>
using namespace std;

char sa[100100];
char sb[100100];
char sc[100100];
int a[100100];
int b[100100];
int c[100100];

inline int convert(char x) {
    if (x >= 'A' && x <= 'F')
        return x - 'A' + 10;
    if (x >= 'a' && x <= 'f')
        return x - 'a' + 10;
    return x - '0';
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        int k;
        scanf("%d", &k);
        scanf("%s", sa);
        scanf("%s", sb);
        scanf("%s", sc);
        int l1 = strlen(sa);
        int l2 = strlen(sb);
        int l3 = strlen(sc);
        int l = max(max(l1, l2), l3);
        for (int x = l - 1, y = l1 - 1; y >= 0; y--, x--)
            a[x] = convert(sa[y]);
        for (int x = l - 1, y = l2 - 1; y >= 0; y--, x--)
            b[x] = convert(sb[y]);
        for (int x = l - 1, y = l3 - 1; y >= 0; y--, x--)
            c[x] = convert(sc[y]);

        int cnt = 0;
        for (int i = 0; i < l; i++) {
            for (int bit = 3; bit >= 0; bit--) {
                int r = (c[i] >> bit) & 1;
                int ab = (a[i] >> bit) & 1;
                int bb = (b[i] >> bit) & 1;
                if (r == 0) {
                    if (ab == 1) {
                        a[i] ^= (1 << bit);
                        cnt++;
                    }
                    if (bb == 1) {
                        b[i] ^= (1 << bit);
                        cnt++;
                    }
                }
                else {
                    if (ab == 0 && bb == 0) {
                        b[i] ^= (1 << bit);
                        cnt++;
                    }
                }
            }
        }

        if (cnt > k) {
            printf("-1\n");
            continue;
        }

        int rem = k - cnt;

        for (int i = 0; i < l && rem > 0; i++) {
            for (int bit = 3; bit >= 0 && rem > 0; bit--) {
                int r = (c[i] >> bit) & 1;
                int ab = (a[i] >> bit) & 1;
                int bb = (b[i] >> bit) & 1;
                if (r == 1) {
                    if (ab == 1 && bb == 1) {
                        a[i] ^= (1 << bit);
                        rem--;
                    }
                    else if (ab == 1) {
                        if (rem >= 2) {
                            a[i] ^= (1 << bit);
                            b[i] ^= (1 << bit);
                            rem -= 2;
                        }
                    }
                }
            }
        }

        int lead = 1;
        for (int i = 0; i < l; i++) {
            if (lead == 1 && a[i] == 0)
                continue;
            else if (a[i] < 10) {
                printf("%d", a[i]);
                lead = 0;
            }
            else {
                printf("%c", a[i] - 10 + 'A');
                lead = 0;
            }
        }
        if (lead == 1)
            printf("0");
        printf("\n");

        lead = 1;
        for (int i = 0; i < l; i++) {
            if (lead == 1 && b[i] == 0)
                continue;
            else if (b[i] < 10) {
                printf("%d", b[i]);
                lead = 0;
            }
            else {
                printf("%c", b[i] - 10 + 'A');
                lead = 0;
            }
        }
        if (lead == 1)
            printf("0");
        printf("\n");

    }
    return 0;
}

