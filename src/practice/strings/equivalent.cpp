#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull p;

char a[200100];
char b[200100];
ull ha[200100], hb[200100];
ull powers[200100];

inline ull plzhash(ull* hashes, int l, int r) {
    ull h = hashes[r];
    if (l) h -= hashes[l - 1];
    return h;
}

int check(int al, int ar, int bl, int br) {
    ull ahash = plzhash(ha, al, ar);
    ull bhash = plzhash(hb, bl, br);
    if (ahash * powers[max(0, bl - al)] == bhash * powers[max(0, al - bl)])
        return 1;

    if (al == ar) return 0;
    if ((ar - al + 1) & 1) return 0;

    int ma = (al + ar) / 2;
    int mb = (bl + br) / 2;
    if (check(al, ma, mb + 1, br) && check(ma + 1, ar, bl, mb))
        return 1;
    if (check(al, ma, bl, mb) && check(ma + 1, ar, mb + 1, br))
        return 1;

    return 0;
}

int main(void) {
    p = rand() % 101;
    powers[0] = 1;
    for (int i = 1; i < 200100; i++)
        powers[i] = powers[i - 1] * p;
    scanf("%s", a);
    int la = strlen(a);
    scanf("%s", b);
    int lb = strlen(b);
    for (int i = 0; i < la; i++) {
        ha[i] = (a[i] - 'a' + 1) * powers[i];
        if (i) ha[i] += ha[i - 1];
    }
    for (int i = 0; i < lb; i++) {
        hb[i] = (b[i] - 'a' + 1) * powers[i];
        if (i) hb[i] += hb[i - 1];
    }
    printf("%s\n", check(0, la - 1, 0, lb - 1) ? "YES" : "NO");
}
