#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, string> pus;
const ull p = 5;

set<ull> hashes;
unordered_map<ull, string> mp;
ull powers[1001000];
string s[300100];
string s1[300100];

int main(void) {
    powers[0] = 1;
    for (int i = 1; i < 1001000; i++)
        powers[i] = p * powers[i - 1];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ull h = 0;
        for (int j = 0; j < s[i].length(); j++)
            h += (s[i][j] - 'a' + 1) * powers[j];
        hashes.insert(h);
        mp[h] = s[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> s1[i];
        ull h = 0;
        int l = s1[i].length();
        for (int j = 0; j < l; j++)
            h += (s1[i][j] - 'a' + 1) * powers[j];
        int flag = 0;
        for (int j = 0; j < l; j++) {
            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s1[i][j]) continue;
                char temp = s1[i][j];
                ull nh = h - ((s1[i][j] - 'a' + 1) * powers[j]) + ((c - 'a' + 1) * powers[j]);
                s1[i][j] = c;
                if (hashes.count(nh) && s1[i] == mp[nh]) {
                    flag = 1;
                    break;
                }
                s1[i][j] = temp;
            }
            if (flag == 1)
                break;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
}
