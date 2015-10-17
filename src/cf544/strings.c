#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int k;
    char *q = (char *) calloc(101, 4);
    scanf("%d", &k);
    scanf("%s", q);
    int l = strlen(q);
    int* seen = (int *) calloc(26, 4);
    int* start = (int *) calloc(101, 4);
    int c = 0;
    int i;
    for (i = 0; i < l; i++) {
        int index = q[i] - 'a';
        if (!seen[index]) {
            start[i] = 1;
            seen[index] = 1;
            c++;
        }
    }
    if (c >= k) {
        printf("YES\n");
        int count = 1;
        printf("%c", q[0]);
        for (i = 1; i < l; i++) {
            if (start[i] == 1) {
                if (count < k) {
                    printf("\n%c", q[i]);
                    count++;
                }
                else {
                    printf("%c", q[i]);
                }
            }
            else {
                printf("%c", q[i]);
            }
        }
    }
    else {
        printf("NO\n");
    }
    return 0;
}
