#include <bits/stdc++.h>
using namespace std;

char s[100100];
int freq[30] = {0};


int main(void) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    if (n > 26)
        printf("-1\n");
    else {
        for (int i = 0; i < n; i++)
            freq[s[i]-'a']++;
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 1)
                cnt += freq[i] - 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
