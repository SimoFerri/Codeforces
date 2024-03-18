#include<stdio.h>
#include<stdlib.h>

int main() {
    int test, n_tests;
    int len, i, res, stato, lett;
    char car;
    int delta[7][6] = { {0, 0, 0, 4, 1, 0}, 
                        {0, 0, 2, 4, 1, 0}, 
                        {0, 3, 0, 4, 1, 0}, 
                        {0, 0, 0, 0, 0, 0}, 
                        {5, 0, 0, 4, 1, 0}, 
                        {0, 0, 0, 4, 6, 0},
                        {0, 0, 0, 0, 0, 0}};

    scanf("%d", &n_tests);
    for(test = 0; test < n_tests; test++) {
        scanf("%d", &len);
        for(i = 0, res = 0, stato = 0; i < len; i++) {
            do {
                scanf("%c", &car);
            } while(car == '\n');
            switch(car) {
                case 'a':
                    lett = 0;
                    break;
                case 'e':
                    lett = 1;
                    break;
                case 'i':
                    lett = 2;
                    break;
                case 'm':
                    lett = 3;
                    break;
                case 'p':
                    lett = 4;
                    break;
                default:
                    lett = 5;
            }
            stato = delta[stato][lett];
            if(stato == 3 || stato == 6) {
                res++;
                stato = delta[stato][0];
            }
        }
        printf("%d\n", res);
    }

    return 0;
}