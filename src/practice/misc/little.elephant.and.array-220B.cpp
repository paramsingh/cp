#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 1e9;

int sq;
struct query {
    int l, r, id;
    query(int a, int b, int c) {
        l = a, r = b, id = c;
    }

    bool operator< (const query& a) const {
        int x = l / sq;
        int y = a.l / sq;
        if (x == y) return r < a.r;
        return x < y;
    }
};

vector<query> queries;
int a[100100];
int ans[100100];
int freq[100100];
int cur = 0;
int n, m;

void add(int x) {
    if (x > n) return;
    if (freq[x] == x)
        cur--;
    freq[x]++;
    if (freq[x] == x)
        cur++;
}

void rm(int x) {
    if (x > n) return;
    if (freq[x] == x)
        cur--;
    freq[x]--;
    if (freq[x] == x)
        cur++;
}


int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sq = (int) sqrt(n);
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        queries.push_back(query(l, r, i));
    }
    sort(queries.begin(), queries.end());
    // l    -> the first index in current range
    // r    -> the last index in current range
    int l = 1, r = 0;
    for (int i = 0; i < queries.size(); i++) {
        int cl = queries[i].l, cr = queries[i].r;
        // add and remove according to range constraints
        while (r < cr)
            add(a[++r]);
        while (r > cr)
            rm(a[r--]);
        while (l < cl)
            rm(a[l++]);
        while (l > cl)
            add(a[--l]);
        ans[queries[i].id] = cur;
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
