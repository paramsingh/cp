#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Polygon {
    long long int key;
    long long int maxx;
    long long int maxy;
};

int cmp(const void *p1, const void *p2){
    struct Polygon *pol1 = (struct Polygon *)p1;
    struct Polygon *pol2 = (struct Polygon *)p2;
    return (pol1 -> maxx >= pol2 -> maxx) && (pol1 -> maxy >= pol2 -> maxy);
}

int main(void){
    int cases;
    long long int n, i, j, vertices, maxx, maxy, x;
    scanf("%d", &cases);
    int term;
    for(term = 0; term<cases; term++){
        scanf("%lld", &n);

        /* array of structs to keep store of polygons */
        struct Polygon polygons[n];

        for(i=0; i<n; i++){
            scanf("%lld", &vertices);
            polygons[i].key = i;
            maxx = maxy = LLONG_MIN;
            for(j=0; j<2*vertices; j++){
                scanf("%lld", &x);
                if(j%2 == 0){
                    if(maxx <= x)
                        maxx = x;
                }
                else{
                    if(maxy <= x)
                        maxy = x;
                }
            }
            polygons[i].maxx = maxx;
            polygons[i].maxy = maxy;
        }

        qsort(polygons, n, sizeof(struct Polygon), cmp);

        long long int ans[n];
        for(i=0;i<n;i++){
            ans[polygons[i].key] = i;
        }

        for(i=0;i<n;i++)
            printf("%lld ", ans[i]);
        printf("\n");
    }
}
