#include <bits/stdc++.h>
using namespace std;


int ans[400100];
char s[400100];


int main(void) {
    set<int, greater<int> > introverts;
    set<int> noone;
    map<int, int> rowids;

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int w;
        scanf("%d", &w);
        noone.insert(w);
        rowids[w] = i;
    }

    scanf("%s", s);
    for (int i = 0; i < 2*n; i++) {
        if (s[i] == '1') {
            int val = *introverts.begin();
            printf("%d ", rowids[val]);
            introverts.erase(val);
        }
        else {
            int val = *noone.begin();
            printf("%d ", rowids[val]);
            noone.erase(val);
            introverts.insert(val);
        }
    }
    return 0;
}

