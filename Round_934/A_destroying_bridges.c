#include<stdio.h>

int main() {
    int n_tests, test, n, k;

    scanf("%d", &n_tests);
    for(test = 0; test < n_tests; test++) {
        scanf("%d %d", &n, &k);
        if(k >= n - 1) {
            printf("%d\n", 1);
        } else {
            printf("%d\n", n);
        }
    }

    return 0;
}