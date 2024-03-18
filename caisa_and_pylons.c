#include<stdio.h>

int main() {
    int max, n, val, i;

    scanf("%d", &n);
    scanf("%d", &max);
    for(i = 1; i < n; i++) {
        scanf("%d", &val);
        if(val > max)
            max = val;
    }
    
    printf("%d\n", max);

    return 0;
}