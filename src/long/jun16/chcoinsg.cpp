#include <bits/stdc++.h>
using namespace std;

// all numbers that are powers of prime are winning positions
// the first losing number is 6 because no matter what Chef removes
// Misha will remove the remaining and Chef will lose
// Since 1 2 3 4 5 are winning positions, any number that is not a multiple
// of 6 can be reduced to a multiple of 6
// therefore all multiples of 6 are losing positions
// qed :)

// P.S: I've done this myself, but the code might be similar to some other
// code because it is very simple and thousands of people may have written
// something like this. Please don't assume I'm cheating. :)

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n % 6 == 0)
            printf("Misha\n");
        else
            printf("Chef\n");
    }
    return 0;
}
