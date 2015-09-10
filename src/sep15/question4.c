#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct island {
    int index;
    int x;
    int y;
};

int main(void) {
    int t;
    scanf("%d", &t);
    int a;
    for (a = 0; a < t; a++) {
        int num;
        scanf("%d", &num);
        struct island maxx, maxy, minx, miny;
        maxx.x = INT_MIN;
        maxy.y = INT_MIN;
        minx.x = INT_MAX;
        miny.y = INT_MAX;
        int i, x, y;
        for (i = 1; i <= num; i++) {
            scanf("%d %d", &x, &y);
            if (maxx.x < x) {
                maxx.x = x;
                maxx.y = y;
                maxx.index = i;
            }
            if (minx.x > x) {
                minx.x = x;
                minx.y = y;
                minx.index = i;
            }
            if (maxy.y < y) {
                maxy.x = x;
                maxy.y = y;
                maxy.index = i;
            }
            if (miny.y > y) {
                miny.x = x;
                miny.y = y;
                miny.index = i;
            }
        }
        int ax = 0, ay = 0;
        int fx = 0, fy = 0;
        if (minx.y < maxx.y) {
            if (minx.y == miny.y) {
                // minx NE
                fx = 1;
                ax = 1;
            }
            else if (maxx.y == maxy.y) {
                // maxx SW
                fx = 2;
                ax = 1;
            }
            else {
                // minx NE
                // maxx SW
                fx = 3;
                ax = 2;
            }
        }
        else {
            if (minx.y == maxy.y) {
                // minx SE
                fx = 4;
                ax = 1;
            }
            else if (maxx.y == miny.y) {
                // maxx NW
                fx = 5;
                ax = 1;
            }
            else {
                // minx SE
                // maxx NW
                fx = 6;
                ax = 2;
            }
        }
        if (maxy.x < miny.x) {
            if (maxy.x == minx.x) {
                // maxy SE
                fy = 1;
                ay = 1;
            }
            else if (miny.x == maxx.x) {
                // miny NW
                fy = 2;
                ay = 1;
            }
            else {
                // maxy SE
                // miny NW
                fy = 3;
                ay = 2;
            }
        }
        else {
            if (maxy.x == maxx.x) {
                // maxy SW
                fy = 4;
                ay = 1;
            }
            else if (miny.x == minx.x) {
                // miny NE
                fy = 5;
                ay = 1;
            }
            else {
                // maxy SW
                // miny NE
                fy = 6;
                ay = 2;
            }
        }
        if (ax < ay) {
            printf("%d\n", ax);
            switch(fx) {
                case 1:
                    printf("%d NE\n", minx.index);
                    break;
                case 2:
                    printf("%d SW\n", maxx.index);
                    break;
                case 3:
                    printf("%d NE\n", minx.index);
                    printf("%d SW\n", maxx.index);
                    break;
                case 4:
                    printf("%d SE\n", minx.index);
                    break;
                case 5:
                    printf("%d NW\n", maxx.index);
                    break;
                case 6:
                    printf("%d SE\n", minx.index);
                    printf("%d NW\n", maxx.index);
                    break;
            }
        }
        else {
            printf("%d\n", ay);
            switch(fy) {
                case 1:
                    printf("%d SE\n", maxy.index);
                    break;
                case 2:
                    printf("%d NW\n", miny.index);
                    break;
                case 3:
                    printf("%d SE\n", maxy.index);
                    printf("%d NW\n", miny.index);
                    break;
                case 4:
                    printf("%d SW\n", maxy.index);
                    break;
                case 5:
                    printf("%d NE\n", miny.index);
                    break;
                case 6:
                    printf("%d SW\n", maxy.index);
                    printf("%d NE\n", miny.index);
                    break;
            }
        }
    }
}
