#include <bits/stdc++.h>
using namespace std;


char s[20];

int main(void) {
    int n;
    scanf("%d", &n);
    int cnt = 0; // count of number of remove commands issued
    int cur = 1;
    stack<int> st;
    for (int i = 1; i <= 2*n; i++) {
        scanf("%s", s);
        if (s[0] == 'a') {
            int x;
            scanf("%d", &x);
            st.push(x);
        }
        else {
            cur++;
            if (st.empty()) continue;
            if (st.top() == cur - 1) {
                st.pop();
            }
            else {
                cnt++;
                while (!st.empty()) st.pop();
            }
        }
    }
    printf("%d\n", cnt);
}
