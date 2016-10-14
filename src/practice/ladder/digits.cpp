#include <bits/stdc++.h>
using namespace std;

struct num {
    int val, req;
    bool operator< (const num& a) const {
        if (req == a.req)
            return val > a.val;
        return req < a.req;
    }
} digits[30], correct[30];

int main(void) {
    int v;
    scanf("%d", &v);
    for (int i = 1; i <= 9; i++) {
        digits[i].val = i;
        scanf("%d", &digits[i].req);
        correct[i].val = i;
        correct[i].req = digits[i].req;
    }
    sort(digits + 1, digits + 10);
    int len = v / digits[1].req;
    if (len == 0) {
        printf("-1\n");
        return 0;
    }
    int rem = v - len * digits[1].req;
    for (int i = 0; i < len; i++) {
        for (int i = 9; i >= 1; i--) {
            if (correct[i].req <= digits[1].req + rem) {
                printf("%d", i);
                rem += digits[1].req - correct[i].req;
                break;
            }
        }
    }
    return 0;
}

