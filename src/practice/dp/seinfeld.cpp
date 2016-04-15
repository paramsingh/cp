#include <bits/stdc++.h>

int main(void) {
    int k = 1;
    while (true) {
        char* c = (char *) calloc(2100, sizeof(char));
        scanf("%s", c);
        if (c[0] == '-') break;
        int l = strlen(c);
        int open = 0, closed = 0, ans = 0;
        for (int i = 0; i < l; i++) {
            if (c[i] == '}') {
                if (open > 0) {
                    open--;
                    closed++;
                }
                else {
                    ans++;
                    open++;
                }
            }
            else {
                open++;
            }
        }
        printf("%d. %d\n", k++, ans + (open / 2));
        free(c);
    }
    return 0;
}
