// Author: Param Singh <paramsingh258@gmail.com>
#include <stdio.h>

int main(void) {
	int t;
	scanf("%d", &t);
	int a;
	for (a = 0; a < t; a++) {
		long long int n, m;
		scanf("%lld %lld", &n, &m);
		long long int ans = 0;
		long long int i, j;
		int ones = 0;
		for (i = 0; i < m; i++) {
			scanf("%lld", &j);
			if (j == 1)
				ones ++;
		}
		long long int not_ones = m - ones;
		while (m > 1) {
			ans++;
			if (ones > 0) {
				if (m > 1){
					m -= 2;
					ones--;
				}
				else {
					m--;
					ones--;
				}
			}
			else {
				m--;
			}
		}
		printf("%lld\n", ans);
	}
}
