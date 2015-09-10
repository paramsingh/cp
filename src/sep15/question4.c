#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct island {
    int x, y, index;
} island;

int main(void) {
    int t;
    scanf("%d", &t);
    int a;
    for (a = 0; a < t; a++) {
        int num;
        scanf("%d", &num);
        int i;
        island* arr  = (island *) calloc(num, 12);
        island* maxx = (island *) calloc(num, 12);
        island* minx = (island *) calloc(num, 12);
        int xmax = INT_MIN, xmin = INT_MAX, ymax = INT_MIN, ymin = INT_MAX;
        int cmaxx = 0, cmaxy = 0, cminx = 0, cminy = 0;
        int x, y;
        for (i = 0; i < num; i++) {
            scanf("%d %d", &x, &y);
            arr[i].x = x;
            arr[i].y = y;
            arr[i].index = i + 1;
            if (xmax < x)
                xmax = x;
            if (xmin > x)
                xmin = x;
            if (ymax < y)
                ymax = y;
            if (ymin > y)
                ymin = y;
        }
        int f = 0, index = -1, ans = 0;
        for (i = 0; i < num; i++) {
            x = arr[i].x;
            y = arr[i].y;
            if (x == xmax) {
                if (y == ymax) {
                    ans = 1;
                    index = i+1;
                    f = 1;
                    break;
                    // direction = SW
                }
                if (y == ymin) {
                    ans = 1;
                    index = i+1;
                    f = 2;
                    break;
                    // direction = NW
                }
                maxx[cmaxx].x = x;
                maxx[cmaxx].y = y;
                maxx[cmaxx].index = i+1;
                cmaxx++;
            }
            if (x == xmin) {
                if (y == ymax) {
                    ans = 1;
                    index = i+1;
                    f = 3;
                    break;
                    // direction = SE
                }
                if (y == ymin) {
                    ans = 1;
                    index = i+1;
                    f = 4;
                    break;
                    // direction = NE
                }
                minx[cminx].x = x;
                minx[cminx].y = y;
                minx[cminx].index = i+1;
                cminx++;
            }
        }
        if (f == 0)
            ans = 2;
        printf("%d\n", ans);
        switch(f) {
            case 1:
                printf("%d SW\n", index);
                break;
            case 2:
                printf("%d NW\n", index);
                break;
            case 3:
                printf("%d SE\n", index);
                break;
            case 4:
                printf("%d NE\n", index);
                break;
            case 0:
                if (maxx[0].y > minx[0].y) {
                    printf("%d SW\n", maxx[0].index);
                    printf("%d NE\n", minx[0].index);
                }
                else {
                    printf("%d NW\n", maxx[0].index);
                    printf("%d SE\n", minx[0].index);
                }
                break;
        }
    }
}


