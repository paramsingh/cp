// Author: Param Singh <paramsingh258@gmail.com>
#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    int *p = (int *) a;
    int *q = (int *) b;
    return (*p) - (*q);
}


void fastread( int *a){
    char c=0;
    while(c<33){
        c=getchar_unlocked();
    }
    *a=0;
    while(c>33){
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

int main(void) {
	int t;
    fastread(&t);
	int a;
	for (a = 0; a < t; a++) {
		int n, m;
        fastread(&n);
        fastread(&m);
	    int arr[m] ;
        int j;
        for (j = 0; j < m; j++){
            fastread(arr+j);
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
