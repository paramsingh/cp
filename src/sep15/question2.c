// Author: Param Singh <paramsingh258@gmail.com>

#include <stdio.h>

int main(void) {
	int t;
	scanf("%d", &t);
	int a;
	for (a = 0; a < t; a++) {
		int n, m;
		scanf("%d %d", &n, &m);
		int ans = 0;
		int i;
		int flag = 0;
		int ones = 0;
		for (i = 0; i < m; i++) {
			int j;
			scanf("%d", &j);
			if (j == 1)
				ones ++;
		}
		int not_ones = m - ones;
		while (m != 1) {
			ans ++;
			if (ones > 0) {
				if (m > 1){
					m -= 2;
					ones --;
				}
				else {
					m--;
					ones--;
				}
			}
			else {
				m -= 1;
			}
		}
		printf("%d\n", ans);
	}
}
