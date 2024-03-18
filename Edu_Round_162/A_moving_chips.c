#include<stdio.h>

int main() {
    int i, first, last, sum, n, m, is_started, tests, t;

    scanf("%d", &tests);
    for(t = 0; t < tests; t++) {
        scanf("%d", &n);
        for(i = 0, is_started = 0, sum = 0; i < n; i++) {
            scanf("%d", &m);
            if(!is_started && m) {
                first = i;
                last = i;
                is_started = 1;
            } else if(is_started && m)
                last = i;
            
            sum += m;
            //printf("i: %d, first: %d, last: %d, sum: %d\n", i, first, last, sum);
        }
        printf("%d\n", last - first + 1 - sum);
    }

    return 0;
}