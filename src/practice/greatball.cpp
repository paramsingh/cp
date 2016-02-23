// Problem: A series of people enter the ball at x[i] time and exit at y[i] time.
// Have  to find the maximum number of people at the ball at any given time.

// Strategy: Process arrival and departure in increasing order of time and
// count how many people are at the ball. The maximum number of people will be the
// answer.

#include <bits/stdc++.h>
using namespace std;

class event {
    public:
        int type;
        int time;
        event(int a, int b) {
            type =  a, time = b;
        }
};

bool cmp(const event& a, const event& b) {
    return a.time < b.time;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<event> ev;
        for (int i = 0; i < n; i++) {
            int a, d;
            scanf("%d %d", &a, &d);
            ev.push_back(event(1, a));
            ev.push_back(event(-1, d));
        }
        sort(ev.begin(), ev.end(), cmp);
        int people = 0; // stores the number of people at time t
        int mx = -1;     // stores the answer
        for (int t = 0; t < ev.size(); ) {
            int cur = ev[t].time;
            while (t < ev.size() && ev[t].time == cur) {
                people += ev[t].type;
                t++;
            }
            mx = max(people, mx);
        }
        printf("%d\n", mx);
    }
    return 0;
}


