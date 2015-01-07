#include <stdio.h>

int main( void )
{
	int t;
	scanf("%d", &t);
	int term;
	for(term = 0; term<t; term++){
		int n, k;
		scanf("%d %d", &n, &k);
		int a[n];
		int b[n];
		int i;
		for(i=0;i<n;i++)
			scanf("%d", a+i);
		for(i=0;i<n;i++)
			scanf("%d", b+i);
		int max = (k/a[0]) * b[0];
		for(i=0;i<n;i++){
			int t;
			t = (k/a[i]) * b[i];
			if( max < t )
				max = t;
		}
		printf("%d\n", max);
	}	
}