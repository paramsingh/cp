#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull power(ull n, int a) {
    if (n == 1 || a == 0)
        return 1;
    if (a == 1)
        return n;
    ull half = power(n, a / 2);
    if (a % 2 == 0)
        return half * half;
    else
        return half * half * n;
}

const int prime = 29;

char pattern[1001000];
char text[1001000];
vector<int> matches;

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        scanf("%s", pattern);
        scanf("%s", text);
        int l = strlen(text);
        ull p = power(prime, n - 1);
        ull phash = 0, thash = 0;
        for (int i = 0; i < n; i++) {
            phash = phash * prime + pattern[i] - 'a';
            thash = thash * prime + text[i] - 'a';
        }
        if (phash == thash)
            matches.push_back(0);
        int s = 0;
        for (int i = n; i < l; i++) {
            thash = thash - (text[s] - 'a') * p;
            thash = thash * prime + text[i] - 'a';
            s++;
            if (phash == thash)
                matches.push_back(s);
        }
        if (matches.empty())
            printf("\n");
        for (int i = 0; i < matches.size(); i++)
            printf("%d\n", matches[i]);
        matches.clear();
    }
    return 0;
}



