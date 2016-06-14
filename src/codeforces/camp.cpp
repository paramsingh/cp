#include <bits/stdc++.h>
using namespace std;

string s;
int main(void) {
    int i = 1;
    while (s.length() < 1000) {
        string n;
        int dup = i;
        while (dup != 0) {
            n += ((dup % 10) + '0');
            dup /= 10;
        }
        reverse(n.begin(), n.end());
        s += n;
        i++;
    }
    int num;
    scanf("%d", &num);
    cout << s[num-1] << endl;
    return 0;
}
