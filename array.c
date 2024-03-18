#include<stdio.h>

#define DIM 100

int main() {
    int arr1[DIM], arr2[DIM], arr3[DIM];
    int dim1, dim2, dim3, dim_tot;
    int i, input, n, tmp, is_tmp, arr1_ready, arr2_ready;

    scanf("%d", &dim_tot);
    dim1 = dim2 = dim3 = 0;
    for(input = 0, arr1_ready = 0, arr2_ready = 0, is_tmp = 0; input < dim_tot; input++) {
        scanf("%d", &n);
        if(n == 0) {
            arr3[dim3] = n;
            dim3++;
        } else if(n < 0) {
            if(!arr1_ready) {
                arr1[dim1] = n;
                dim1++;
                arr1_ready = 1;
            } else if(!arr2_ready) { 
                if(!is_tmp) {
                    tmp = n;
                    is_tmp = 1;
                } else if(is_tmp) {
                    arr2[dim2] = tmp;
                    dim2++;
                    arr2[dim2] = n;
                    dim2++;
                    is_tmp = 0;
                    arr2_ready = 1;
                }
            } else {
                arr3[dim3] = n;
                dim3++;
            }
        } else if(n > 0) {
            arr2[dim2] = n;
            dim2++;
        }
    }
    if(is_tmp) {
        arr3[dim3] = tmp;
        dim3++;
    }

    printf("%d ", dim1);
    for(i = 0; i < dim1; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    printf("%d ", dim2);
    for(i = 0; i < dim2; i++)
        printf("%d ", arr2[i]);
    printf("\n");

    printf("%d ", dim3);
    for(i = 0; i < dim3; i++)
        printf("%d ", arr3[i]);
    printf("\n");


    return 0;
}