#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int dividers[5] = {2, 3, 4, 5, 6};

int change[7] = {2, 1, 3, 2};

int grundy(lli num) {
//    printf("call to %d\n", num);
    if (num == 0)
        return 0;
    lli n = 1;
    int mul = 0;
    lli cur = 1;
    int gd = 1;
    while (true) {
//        printf("cur = %d,range = %lld - %lld\n", cur, n, n + cur - 1);
        if (n <= num && num <= n + cur - 1) {
            return gd;
        }
        else {
            n = n + cur;
            gd = (gd + 1) % 4;
            cur = cur * change[mul];
            mul = (mul + 1) % 4;
        }
    }
}

map<int, int> gn;
int gnbf(int num) {
    if (num == 0)
        return 0;
    if (gn.count(num))
        return gn[num];
    set<int> s;
    for (int i = 0; i < 5; i++)
        s.insert(gnbf(num / dividers[i]));
    int i = 0;
    while (true) {
        if (s.count(i))
            i++;
        else
            return gn[num] = i;
    }
}

int n;
lli a[1000];

int main(void) {
    int t;
    int prev = 0;
    int cnt = 0;
/*    for (int i = 0; i < 2000000; i++) {
//        printf("g[%d] = %d\n", i, gnbf(i));
        if (prev == gnbf(i))
            cnt++;
        else {
            printf("g = %d, cnt = %d\n", gnbf(i-1), cnt);
            cnt = 1;
        }
        prev = gnbf(i);
    }
    return 0;*/
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        lli v = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", a+i);
        }
        for (int i = 0; i < n; i++) {
            v ^= grundy(a[i]);
        }
        prev = cnt;
        if (v == 0) {
            printf("Derek\n");
        }
        else {
            printf("Henry\n");
        }
    }
    return 0; }

