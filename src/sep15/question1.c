#include <stdio.h>
#include <math.h>

struct position {
	int x, y;
};

int main(void) {
	int t;
	scanf("%d", &t);
	int i;
	for (i = 0; i < t; i++) {
		int n, sum = 0;
		scanf("%d", &n);
		struct position arr[n*n+1];
		int j, k;
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				int a;
				scanf("%d", &a);
				arr[a].x = j;
				arr[a].y = k;
			}
		}
		for (j = 2; j <= n*n; j++) {
			sum += fabs(arr[j].x - arr[j-1].x) + fabs(arr[j].y - arr[j-1].y);
		}
		printf("%d\n", sum);
	}
} 
