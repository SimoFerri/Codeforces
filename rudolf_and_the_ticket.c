#include<stdio.h>
#include<stdlib.h>

int main() {
    int n_tests, test;
    int n, m, k, val, *arr, ways;
    int i, j;

    scanf("%d", &n_tests);
    for(test = 0; test < n_tests; test++) {
        scanf("%d %d %d", &n, &m, &k);
        arr = malloc(sizeof(int) * n);
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        for(i = 0, ways = 0; i < m; i++) {
            scanf("%d", &val);
            for(j = 0; j < n; j++) {
                if(arr[j] + val <= k)
                    ways++;
            }
        }
        free(arr);
        printf("%d\n", ways);
    }

    return 0;
}