// 23:55
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull dp[2][30][40][1050];

ull ans(int lead, int digit, int even, int mask) {
    if (dp[lead][digit][even][mask] != -1)
        return dp[lead][digit][even][mask];

    if (digit == 0) {
        ull flag = 1;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                if ((even >> (i / 2)) & 1) {
                    if ((mask >> i) & 1)
                        continue;
                    else
                        flag = 0;
                }
            }
            else if ((mask >> i) & 1)
                flag = 0;
        }
        return dp[lead][digit][even][mask] = flag;
    }

    if (digit == 1) {
        ull cnt = 0;
        int need = 0;
        if (lead == 0) {
            if (even & 1) {
                if (!(mask & 1))
                    need++;
            }
            else
                cnt++;
        }

        for (int i = 1; i < 10; i++) {
            if (i % 2 == 0) {
                if ((even >> (i / 2)) & 1) {
                    if ((mask >> i) & 1)
                        continue;
                    else
                        need++;
                }
                else
                    cnt++;
            }
            else {
                if ((mask >> i) & 1)
                    need++;
            }
        }
        if (need > 1)
            return dp[lead][digit][even][mask] = 0;
        else if (need == 1)
            return dp[lead][digit][even][mask] = 1;
        else
            return dp[lead][digit][even][mask] = cnt;
    }

    ull cnt = 0;
    for (int i = 1; i < 10; i++) {
        if (i % 2 == 0) {
            if ((even >> (i / 2)) & 1)
                cnt += ans(0, digit - 1, even, mask ^ (1 << i));
            else
                cnt += ans(0, digit - 1, even | (1 << (i / 2)), mask ^ (1 << i));
        }
        else {
            cnt += ans(0, digit - 1, even, mask ^ (1 << i));
        }
    }
    if (lead == 0) {
        if (even & 1)
            cnt += ans(0, digit - 1, even, mask ^ 1);
        else
            cnt += ans(0, digit - 1, even | 1, mask ^ 1);
    }

    return dp[lead][digit][even][mask] = cnt;
}

ull calc(ull n) {
    if (n == 0 || n == 1)
        return 0;
    string s;
    ull x = n;
    while (x != 0) {
        s += (char)((x % 10) + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    int l = s.length();
    ull cnt = 0;
    // add numbers of digits less than n;
    for (int i = 1; i < l; i++)
        cnt += ans(1, i, 0, 0);

    // add numbers having the same length as n but smaller or equal
    int mask = 0, even = 0;
    for (int i = 1; i <= l; i++) {
        for (int j = 0; j < s[i - 1] - '0'; j++) {
            if (i == 1 && j == 0)
                continue;
            if (j % 2 == 0) {
                if ((even >> (j / 2)) & 1)
                    cnt += ans(0, l - i, even, mask ^ (1 << j));
                else
                    cnt += ans(0, l - i, even | (1 << (j / 2)), mask ^ (1 << j));
            }
            else
                cnt += ans(0, l - i, even, mask ^ (1 << j));
        }
        int c = s[i - 1] - '0';
        if (c % 2 == 0)
            even |= (1 << (c / 2));
        mask = mask ^ (1 << c);
    }
    cnt += ans(0, 0, even, mask);
    return cnt;
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    int t;
    scanf("%d", &t);
    while (t--) {
        ull a, b;
        scanf("%llu %llu", &a, &b);
        ull na = calc(a - 1);
        ull nb = calc(b);
        printf("%llu\n", nb - na);
    }
    return 0;
}
