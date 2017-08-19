#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt += x % 2;
	}
	if (cnt > 0)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}

