#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int perimeter[30][40000];
lli freq[30][40000];
int n;
int h[20];

void ans(int id, int mask) {
    if (perimeter[id][mask] != -1)
        return;

    if (mask == ((1 << n) - 1)) {
        perimeter[id][mask] = h[id];
        freq[id][mask] = 1;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (((mask >> i) & 1) == 0) {
                int nm = mask | (1 << i);
                ans(i, nm);
                int np = perimeter[i][nm] + abs(h[i] - h[id]);
                if (perimeter[id][mask] < np) {
                    perimeter[id][mask] = np;
                    freq[id][mask] = freq[i][nm];
                }
                else if (perimeter[id][mask] == np) {
                    freq[id][mask] += freq[i][nm];
                }
            }
        }
    }
}

int main(void) {
    scanf("%d", &n);
    while (n != 0) {
        memset(perimeter, -1, sizeof(perimeter));
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++)
            scanf("%d", h + i);
        int s = 0; lli f = 0;
        for (int i = 0; i < n; i++) {
            ans(i, 1 << i);
            if (perimeter[i][1 << i] + h[i] > s) {
                s = perimeter[i][1 << i] + h[i];
                f = freq[i][1 << i];
            }
            else if (perimeter[i][1 << i] + h[i] == s)
                f += freq[i][1 << i];
        }
        s += n << 1;
        printf("%d %lld\n", s, f);
        scanf("%d", &n);
    }
    return 0;
}

