// http://www.spoj.com/problems/PICAD/

#include <bits/stdc++.h>
using namespace std;

class event {
    public: int type;
            int time;
            event(int t, int ti) {
                type = t;
                time = ti;
            }
};

int cmp(event a, event b) {
    return a.time < b.time;
}

int main(void) {
    int t = 10;
    while (t--) {
        int p, k;
        scanf("%d %d", &p, &k);
        int n;
        scanf("%d", &n);
        vector<event> events;
        int people = 0;
        for (int i = 0; i < n; i++) {
            int come, go;
            scanf("%d %d", &come, &go);
            events.push_back(event(1, come));
            events.push_back(event(-1, go));
        }
        sort(events.begin(), events.end(), cmp);
        int mx = -1, mn = 100000000;
        int first = 0;
        for (int i = 0; i < events.size();) {
            int t = events[i].time;
            int start = i;
            if (first == 0 && p < t) {
                first = 1;
                mn = min(mn, people);
                mx = max(mx, people);
            }
            while (t == events[start].time && start < events.size()) {
                if (events[start].type == 1)
                    people++;
                start++;
            }
            if (p <= t && t <= k) {
                mn = min(mn, people);
                mx = max(mx, people);
            }
            start = i;
            while (t == events[start].time && start < events.size()) {
                if (events[start].type == -1)
                    people--;;
                start++;
            }
            if (p <= t && t < k) {
                mx = max(mx, people);
                mn = min(mn, people);
            }
            i = start;
        }
        if (mx == -1)
            printf("%d %d\n", people, people);
        else
            printf("%d %d\n", mn, mx);
    }
    return 0;
}

