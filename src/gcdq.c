#include <stdio.h>

int hcf( int a, int b )
{
	while( a != b ){
		if( a > b )
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int main( void )
{
	int t;
	scanf("%d", &t);
	while( t-- ){
		int n, q;
		scanf("%d %d", &n, &q);
		int i;
		int arr[n+1];
		arr[0] = -21313;
		for(i=1;i<=n;i++){
			scanf("%d", arr+i);
		}
		for(i=0; i<q; i++){
			int l,r;
			int j;
			scanf("%d %d", &l, &r);
			int newsize = n - (r - l + 1);
			/* if only one element is left after slicing */
			int sliced[newsize], count = 0;
			for(j=1;j<=n;j++){
				if(j<l || j>r)
					sliced[count++] = arr[j];
			}
			if( newsize == 1 ){
				printf("%d\n", sliced[0]);
				continue;
			}
			int tmp = hcf(sliced[0], sliced[1]);
			for(j=2;j<newsize;j++){
				tmp = hcf(tmp, sliced[j]);
			}

			printf("%d\n", tmp);


		}
	}
}