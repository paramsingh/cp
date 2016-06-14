#include <bits/stdc++.h>
using namespace std;

int k;
int freq[30];
char word[100100];

int main(void) {
    int t;
    scanf("%d", &t);
    int cnt = 1;
    while (t--) {
        memset(freq, 0, sizeof(freq));
        scanf("%s", word);
        scanf("%d", &k);
        int l = strlen(word);
        for (int i = 0; i < l; i++)
            freq[word[i] - 'a']++;
        vector<int> f;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                f.push_back(freq[i]);
        }
        sort(f.begin(), f.end());
        int s = f.size();
        int ans = INT_MAX;
        int prev = 0;
        for (int i = 0; i < s; ) {
            int mn = f[i];
            for (int j = 0; j < i; j++)
                prev += f[j];
            int x = 0;
            int req = mn + k;
            for (int j = i+1; j < s; j++) {
                if (f[j] > req)
                    x += f[j] - req;
            }
            ans = min(ans, x + prev);
            while (f[i] == mn)
                i++;
            prev = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
