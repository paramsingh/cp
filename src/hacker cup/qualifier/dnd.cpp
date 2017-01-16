#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;

double dp[21][21][510];
double pref[21][21][510];

int dices[6] = {4, 6, 8, 10, 12, 20};

int get_dice(string& s) {
    int i = 0;
    while (s[i] != 'd')
        i++;
    i++;
    int d = 0;
    while (i < s.length() && '0' <= s[i] && s[i] <= '9') {
        d = d * 10 + s[i] - '0';
        i++;
    }
    return d;
}

int get_rolls(string& s) {
    int i = 0;
    int r = 0;
    while (i < s.length() && '0' <= s[i] && s[i] <= '9') {
        r = r * 10 + s[i] - '0';
        i++;
    }
    return r;
}

int get_add(string& s) {
    int i = 0, a = 0;
    while (i < s.length() && s[i] != '+' && s[i] != '-')
        i++;
    if (i == s.length())
        return 0;
    int sign = s[i] == '+' ? 1 : -1;
    i++;
    while (i < s.length() && '0' <= s[i] && s[i] <= '9') {
        a = a * 10 + s[i] - '0';
        i++;
    }
    return a * sign;
}

int main(void) {
    for (int i = 0; i < 6; i++) {
        int d = dices[i];
        for (int get = 1; get <= d; get++) {
            dp[d][1][get] = 1 / (double) d;
        }
        for (int rolls = 2; rolls <= 20; rolls++) {
            for (int need = 1; need < 510; need++) {
                dp[d][rolls][need] = 0;
                for (int get = 1; get <= d && need > get; get++)
                    dp[d][rolls][need] += dp[d][rolls - 1][need - get] / d;
            }
            double s = 0;
            for (int need = 0; need < 510; need++) {
                s += dp[d][rolls][need];
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        int strength, spells;
        scanf("%d %d", &strength, &spells);
        double ans = 0;
        for (int i = 1; i <= spells; i++) {
            string s;
            cin >> s;
            int dice = get_dice(s);
            int rolls = get_rolls(s);
            int add = get_add(s);
            int min_req = strength - add;
            double p = 0;
            for (int x = max(0, min_req); x <= 500; x++)
                p += dp[dice][rolls][x];
            ans = max(ans, p);
        }
        printf("Case #%d: %.15lf\n", test, ans);
    }
}
