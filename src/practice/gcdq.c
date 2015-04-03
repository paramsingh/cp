#include <stdio.h>

int hcf( int a, int b )
{
	int tmp;
	while(b){
		tmp = a % b;
		a = b;
		b = tmp;
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
			if( newsize == 1){
				if(l==1)
					printf("%d\n", arr[r+1]);
				else
					printf("%d\n", arr[l-1]);
				continue;
			}
			int tmp=0;
			if(l==2)
				tmp = hcf(arr[1],arr[r+1]);
			else if(l==1)
				tmp = hcf(arr[r+1], arr[r+2]);
			else
				tmp = hcf(arr[1],arr[2]);

			for(j=1;j<=n;j++){
				if(j<l || j>r)
					tmp = hcf(tmp, arr[j]);
			}

			/* if only one element is left after slicing */
			/*int sliced[newsize], count = 0;
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
			}*/


			printf("%d\n", tmp);


		}
	}
}