#include <stdio.h>
#include <stdlib.h>

struct row {
    int num;
    int* vals;
    int count;
};

int cmp(const void* p1, const void* p2){
    struct row* r1 = (struct row*) p1;
    struct row* r2 = (struct row*) p2;
    return (r1->count) < (r2->count);
}

int dfs(struct row* mat, int* visited, int i, int n){
    printf("%d ", i);
    visited[i] = 1;
    int j;
    for(j=0; j<n; j++){
        if(mat[mat[i].num].vals[j]){
            if(!visited[j])
                return dfs(mat, visited, j, n);
            else
                return 0;
        }
    }
    return 1;
}

int main(void){
    int cases;
    scanf("%d", &cases);
    while(cases--){
        printf("Case #%d: \n", cases);
        int n, flag = 0;
        scanf("%d", &n);
        int **a = (int **) calloc(n, sizeof(int *));
        struct row* diff = (struct row*) calloc(n, sizeof(struct row));
        int i, j, cur;
        for(i=0; i<n; i++){
            diff[i].num = i;
            diff[i].count = 0;
            diff[i].vals = (int *) calloc(n, sizeof(int));
            a[i] = (int *) calloc(n, sizeof(int));
            for(j=0; j<n; j++){
                scanf("%d", &a[i][j]);

                if(a[i][j] == 1 && i == j)
                    flag = 1;

                if(a[i][j] == 1){
                    diff[i].vals[j] = 1;
                    diff[i].count++;
                }
            }
        }
        if(flag == 1){
            printf("Diagonal\n");
            continue;
        }

        int *visited = (int *) calloc(n, 8);
        /*
        printf("Before sort: \n");
        for(i=0; i<n; i++){
            cur = diff[i].num;
            for(j=0; j<n; j++){
                printf("%d ", diff[cur].vals[j]);
            }
            printf("\n");
        }
        */

        qsort(diff, n, sizeof(struct row), cmp);

        int df = dfs(diff, visited, 0, n);
        if(!df){
            printf("DFS\n");
            continue;
        }

        /*
        printf("After Sort: \n");
        for(i=0; i<n; i++){
            cur = diff[i].num;
            for(j=0; j<n; j++){
                printf("%d ", diff[i].vals[j]);
            }
            printf("\n");
        }
        printf("\n");
        */

        int *y = (int *) calloc(n, 8);
        for(i=0; i<n; i++)
            y[i] = -1;
        int count[2] = {0};

        for(i=0; i<n; i++){
            cur = diff[i].num;
            for(j=0; j<n; j++){
                if(diff[i].vals[j]){
                    if(y[cur] == -1 && y[j] == -1){
                        y[cur] = 0;
                        y[j] = 1;
                        count[0]++;
                        count[1]++;
                    }
                    else if(y[cur] == -1){
                        int x = !y[j];
                        y[cur] = x;
                        count[x]++;
                    }
                    else if(y[j] == -1){
                        int x = !y[cur];
                        y[j] = x;
                        count[x]++;
                    }
                }
                // printf("%d ", y[j]);
            }
            // printf("\n");
        }
        // printf("\nAfter differences have been filled: \n");

        for(i=0; i<n; i++){
            // printf("%d ", y[i]);
            if(y[i] == -1){
                if(count[1] < count[0]){
                    y[i] = 1;
                    count[1] ++;
                }
                else {
                    y[i] = 0;
                    count[0]++;
                }
            }
        }
        // printf("\nAnswer: \n");
        for(i=0; i<n; i++)
            printf("%d ", y[i]);
        printf("\n");
    }
}
