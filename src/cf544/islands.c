#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int** a = (int **) calloc(n, sizeof(int *));
    int i, j;
    int count = 0;
    for (i = 0; i < n; i++) {
        a[i] = (int *) calloc(n, sizeof(int));
        if (i % 2 == 0) {
            for (j = 0; j < n; j+=2) {
                a[i][j] = 1;
                count++;
            }
        }
        else {
            for (j = 1; j < n; j+=2) {
                a[i][j] = 1;
                count++;
            }
        }
    }
    if (count >= k) {
        printf("YES\n");
        int c = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    if (c < k) {
                        printf("L");
                        c++;
                    }
                    else {
                        printf("S");
                    }
                }
                else
                    printf("S");
            }
            printf("\n");
        }
    }
    else {
        printf("NO\n");
    }
    return 0;
}

