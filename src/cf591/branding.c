#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char alphabet[26];
    int pos[26];
    int n, m;
    int i, j;
    for (i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;
        pos[i] = i;
    }
    scanf("%d %d", &n, &m);
    char s[n+1];
    scanf("%s", s);
    char* a[n+1];
    for (i = 0; i < n; i++) {
        a[i] = alphabet + (s[i] - 'a');
    }
    for (i = 0; i < m; i++) {
        char x, y;
        scanf(" %c %c", &x, &y);
        alphabet[pos[y-'a']] = x;
        alphabet[pos[x-'a']] = y;
        int temp = pos[x-'a'];
        pos[x - 'a'] = pos[y - 'a'];
        pos[y - 'a'] = temp;
    }
    for (j = 0; j < n; j++) {
        printf("%c", *(a[j]));
    }
    printf("\n");
    return 0;
}
