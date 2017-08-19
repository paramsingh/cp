#include <bits/stdc++.h>
using namespace std;

char s[10100];
int freq[100];

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
			freq[s[i] - 'a']++;
	// try to assign each color to different friends
	// if some color gets left, you're fucked
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < k; j++)
				if (freq[i]) freq[i]--;
		if (freq[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
