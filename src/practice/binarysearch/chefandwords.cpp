#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct str {
    string s;
    ll cost;
    str(string a, ll b) {
        s = a; cost = b;
    }
    bool operator< (const str& b) const {
        if (cost == b.cost)
            return s < b.s;
        return cost > b.cost;
    }
};

bool cmp(const str& a, const str& b) {
    return a.s < b.s;
}

vector<str> first, second, first1;
vector<char> word;
int fs, ss;
ll p[30][30];
int n, m;
ll k;

void genFirst(int i, ll cost) {
    if (i == fs) {
        string s;
        for (auto c: word)
            s += c;
        first.push_back(str(s, cost));
        first1.push_back(str(s, cost));
    }
    else {
        for (char c = 'a'; c < 'a' + n; c++) {
            word.push_back(c);
            genFirst(i + 1, cost + p[i][c - 'a']);
            word.pop_back();
        }
    }
}

void genSecond(int i, ll cost) {
    if (i == ss) {
        string s;
        for (auto c: word)
            s += c;
        second.push_back(str(s, cost));
    }
    else {
        for (char c = 'a'; c < 'a' + n; c++) {
            word.push_back(c);
            genSecond(i + 1, cost + p[i + fs][c - 'a']);
            word.pop_back();
        }
    }
}

inline ll check(ll val) {
    int right = second.size() - 1;
    ll ans = 0;
    for (int i = 0; i < first.size(); i++) {
        ll c = first[i].cost;
        while (right > 0 && (c + second[right].cost) < val)
            right--;
        if (second[right].cost + first[i].cost >= val)
            ans += right + 1;
    }
    return ans;
}

int main(void) {
    scanf("%d %d %lld", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            scanf("%lld", &p[i][j]);
    }
    if (m == 1) {
        fs = m;
        genFirst(0, 0);
        sort(first.begin(), first.end());
        printf("%s\n", first[k - 1].s.c_str());
        return 0;
    }
    fs = m / 2; ss = m - fs;
    genFirst(0, 0);
    sort(first.begin(), first.end());
    genSecond(0, 0);
    sort(second.begin(), second.end());
    ll lo = 0, hi = 1e10 + 10;
    while (lo < hi) {
        ll mid = (lo + hi + 1) >> 1;
        if (check(mid) >= k)
            lo = mid;
        else
            hi = mid - 1;
    }
    ll fin = lo;
    k = k - check(lo + 1);
    for (int i = 0; i < first1.size(); i++) {
        ll req = fin - first1[i].cost;
        // left bound first value <= req
        int lo = 0, hi = second.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (second[mid].cost > req)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (second[lo].cost != req)
            continue;
        int left = lo;
        // right bound: last value >= req
        lo = 0, hi = second.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (second[mid].cost < req)
                hi = mid - 1;
            else
                lo = mid;
        }
        int right = lo;
        int cnt = right - left + 1;
        if (cnt >= k) {
            printf("%s%s\n", first1[i].s.c_str(), second[left + k - 1].s.c_str());
            return 0;
        }
        k -= cnt;
    }
    return 0;
}
