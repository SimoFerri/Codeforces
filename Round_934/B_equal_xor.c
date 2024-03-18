#include<stdio.h>
#include<stdlib.h>

int main() {
    int test, n_tests, n, k, i, j, h;
    int *arr1, *arr2, *res1, *res2;

    scanf("%d", &n_tests);
    for(test = 0; test < n_tests; test++) {
        scanf("%d %d", &n, &k);

        arr1 = malloc(sizeof(int) * n);
        arr2 = malloc(sizeof(int) * n);
        for(i = 0; i < n; i++)
            scanf("%d", &arr1[i]);
        
        for(i = 0; i < n; i++)
            scanf("%d", &arr2[i]);

        
    }

    return 0;
}