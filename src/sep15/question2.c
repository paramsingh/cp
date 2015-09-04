// Author: Param Singh <paramsingh258@gmail.com>
#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    int *p = (int *) a;
    int *q = (int *) b;
    return (*p) - (*q);
}

int main(void) {
	int t;
	scanf("%d", &t);
	int a;
	for (a = 0; a < t; a++) {
		int n, m;
		scanf("%d %d", &n, &m);
	    int arr[m] ;
        int j;
        for (j = 0; j < m; j++){
            scanf("%d", &arr[j]);
        }
        qsort(arr, m, 4, compare);
        int dup = m;
        int index = 0;
        int ans = 0;
        while (dup > 1) {
            int x = arr[index];
            index++;
            if ( dup >= x + 1 ) {
                dup -= x+1;
                ans += x;
            }
            else {
                ans += dup - 1;
                dup = 1;
            }
        }
        printf("%d\n", ans);
	}
}
