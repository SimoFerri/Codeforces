#include<stdio.h>

#define DIM 100
#define DIM_LIM 10

int main() {
    char str[DIM + 1], str_tmp[DIM_LIM + 1];
    int n, i, j, t, pot, len;

    scanf("%d", &n);
    for(t = 0; t < n; t++) {
        scanf("%s", str);
        str_tmp[0] = str[0];
        for(i = 0, j = 1; str[i] != '\0' && str[i + 1] != '\0'; i++);
        len = i + 1;
        if(len > DIM_LIM) {
            len -= 2;
            for(pot = 10; pot <= len; pot *= 10);
            pot /= 10;
            while(pot > 0) {
                str_tmp[j] = len / pot + '0';
                j++;
                len = len % pot;
                pot /= 10;
            }
            str_tmp[j] = str[i];
            j++;
            str_tmp[j] = '\0';
            printf("%s\n", str_tmp);
        } else {
            printf("%s\n", str);
        }
    }

    return 0;
}