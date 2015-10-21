// Author: Param Singh <paramsingh258@gmail.com>
// Nikitosh and Xor: https://www.codechef.com/problems/REBXOR

#include <stdio.h>
#define size 10000000

void fastread(int *a) {
    char c = 0;
    while (c < 33)
        c = getchar_unlocked();
    *a = 0;
    while (c > 33) {
        *a = (*a) * 10 + (c-'0');
        c = getchar_unlocked();
    }
}

struct node {
    int left;
    int right;
};
struct node trie[size];
int root = 0;
int count = 1;

void insert(int n);
void init() {
    count = 1;
    int i;
    for (i = 0; i < size; i++) {
        trie[i].left = -1;
        trie[i].right = -1;
    }
    insert(0);
}

void insert(int n) {
    int i;
    int node = root;
    for (i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (bit == 0) {
            if (trie[node].left == -1)
                trie[node].left = (count++);
            node = trie[node].left;
        }
        else {
            if (trie[node].right == -1)
                trie[node].right = (count++);
            node = trie[node].right;
        }
    }
}

int query(int n) {
    int i;
    int ans = 0;
    int node = root;
    for (i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (bit == 0) {
            if (trie[node].right == -1) {
                node = trie[node].left;
            }
            else {
                ans += (1 << i);
                node = trie[node].right;
            }
        }
        else {
            if (trie[node].left == -1)
                node = trie[node].right;
            else {
                ans += (1 << i);
                node = trie[node].left;
            }
        }
    }
    return ans;
}

int main(void) {
    int n;
    fastread(&n);
    int a[n];
    int rev[n];
    int i;
    for (i = 0; i < n; i++)
        fastread(a+i);
    init();
    int ans = 0, prev = 0;
    for (i = n - 1; i >= 0; i--) {
        prev = prev ^ a[i];
        insert(prev);
        int x = query(prev);
        if (x > ans) {
            ans = x;
        }
        rev[i] = ans;
    }
    int ans2 = 0, max = 0;
    prev = 0;
    init();
    for (i = 0; i < n-1; i++) {
        prev = prev ^ a[i];
        insert(prev);
        int x = query(prev);
        if (x > ans2) {
            ans2 = x;
        }
        if (ans2 + rev[i+1] > max) {
            max = ans2 + rev[i+1];
        }
    }
    printf("%d\n", max);
    return 0;
}
