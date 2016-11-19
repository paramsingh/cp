#include <bits/stdc++.h>
using namespace std;

int trie[2500001][26];
bool mark[2500001];
int nxt = 1;
int root = 0;

char s[1510];
char good[30];

int main(void) {
    scanf("%s", s);
    int l = strlen(s);
    scanf("%s", good);
    int k;
    scanf("%d", &k);
    int ans = 0;
    for (int i = 0; i < l; i++) {
        int here = i;
        int node = root;
        int cnt = 0;
        while (cnt <= k && here < l) {
            cnt += good[s[here] - 'a'] == '0';
            if (cnt > k) break;
            if (trie[node][s[here] - 'a'] == 0)
                trie[node][s[here] - 'a'] = nxt++;
            node = trie[node][s[here] - 'a'];
            if (mark[node] == 0) {
                ans++;
                mark[node] = 1;
            }
            here++;
        }
    }
    printf("%d\n", ans);
}
