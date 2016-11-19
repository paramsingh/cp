#include <bits/stdc++.h>
using namespace std;

set<int> fin;
int a[100100];

int main(void) {
    int n;
    scanf("%d", &n);
    set<int> mp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        set<int> n;
        for (int x: mp)
            n.insert(x | a[i]);
        n.insert(a[i]);
        mp.clear();
        for (int x: n) {
            mp.insert(x);
            fin.insert(x);
        }
    }
    printf("%d\n", (int)fin.size());
}
