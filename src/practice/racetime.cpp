#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int len;

class block {
    public: int b, e;
            vector<int> vals;
};

block* blocks;

int idx[100100];

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", arr+i);
    len = (int)(sqrt(n));
    blocks = (block*) calloc(len+10, sizeof(block));
    int count = 0;
    int nb = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0)
            blocks[nb].b = i;
        blocks[nb].vals.push_back(arr[i]);
        idx[i] = nb;
        count++;
        if (count == len || i == n-1) {
            count = 0;
            blocks[nb].e = i;
            sort(blocks[nb].vals.begin(), blocks[nb].vals.end());
            nb++;
        }
    }
    int i, j, k;
    char type[5];
    while (q--) {
        scanf("%s", type);
        if (type[0] == 'C') {
            scanf("%d %d %d", &i, &j, &k);
            i--; j--;
            int ans = 0;
            for (int x = idx[i]; x <= idx[j]; x++) {
                if (i <= blocks[x].b && j >= blocks[x].e)
                    ans += upper_bound(blocks[x].vals.begin(), blocks[x].vals.end(), k) - blocks[x].vals.begin();
                else {
                    for (int y = max(i, blocks[x].b); y <= min(j, blocks[x].e); y++)
                        if (arr[y] <= k)
                            ans++;
                }
            }
            printf("%d\n", ans);
        }
        else if (type[0] == 'M') {
            scanf("%d %d", &i, &k);
            i--;
            int old = arr[i];
            arr[i] = k;
            int bno = idx[i];
            for (int j = 0; j < blocks[bno].vals.size(); j++) {
                if (blocks[bno].vals[j] == old) {
                    blocks[bno].vals[j] = k;
                    break;
                }
            }
            sort(blocks[bno].vals.begin(), blocks[bno].vals.end());
        }
    }
    return 0;
}
