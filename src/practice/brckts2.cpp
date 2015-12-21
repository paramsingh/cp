#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

char s[350000];

int main(void) {
    int t;
    scanf("%d", &t);
    int i;
    while (t--) {
        scanf("%s", s);
        long long int len = strlen(s);
        stack<int> st;
        stack<long long int> ht;
        long long int area = 0;
        long long int w;
        for (i = 0; i < len; i++) {
            st.push(i);
            ht.push(1);
            long long int sign = -1;
            while (!st.empty()) {
                i++;
                if (s[i] == '(') {
                    ht.push(1);
                    st.push(i);
                    sign = -sign;
                }
                else {
                    int e = st.top();
                    w = i - e;
                    sign = -sign;
                    long long int x = ht.top();
                    area = area + (sign * w * x);
                    st.pop();
                    ht.pop();
                    if (ht.size() != 0 && ht.top() < x + 1)
                        ht.top() = x + 1;
                }
            }
        }
        printf("%lld\n", area);
    }
    return 0;
}
