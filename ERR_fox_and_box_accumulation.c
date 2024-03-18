#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int p, int q, int r);
void merge_sort(int *arr, int p, int r);

int main() {
    int n, i, j, *arr, last_str, tmp, pile, is_valid;

    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, n - 1);

    pile = 0;
    while(n > 0) {
        for(i = n - 2, j = 1, last_str = arr[n - 1], is_valid = last_str; i >= 0 && is_valid >= 0; i--) {
            if(arr[i] < last_str) {
                last_str = arr[i];
                tmp = arr[i];
                arr[i] = arr[n - 1 - j];
                arr[n - 1 - j] = tmp;
                j++;
                is_valid = last_str;
            } else if (last_str != 0 && arr[i] <= last_str && is_valid > 1) {
                last_str = arr[i];
                tmp = arr[i];
                arr[i] = arr[n - 1 - j];
                arr[n - 1 - j] = tmp;
                j++;
                is_valid--;
            }
        }
        pile++;
        n -= j;
        merge_sort(arr, 0, n - 1);
    }

    printf("%d\n", pile);

    return 0;
}

void merge(int *arr, int p, int q, int r) {
    int dim_l, dim_r, *arr_l, *arr_r;
    int i, j, k;

    dim_l = q - p + 1;      // Lunghezza di arr[p : q]
    dim_r = r - q;          // lunghezza di arr[q + 1 : r]
    
    arr_l = malloc(sizeof(int) * dim_l);
    if(arr_l) {
        arr_r = malloc(sizeof(int) * dim_r);
        if(arr_r) {
            // Popolamento degli array arr_l[0 : dim_l - 1] e arr_r[0 : dim_r - 1]
            for(i = 0; i < dim_l; i++)
                arr_l[i] = arr[p + i];
            for(j = 0; j < dim_r; j++)
                arr_r[j] = arr[q + 1 + j];

            i = 0;          // Indice più basso rimanente in arr_l
            j = 0;          // Indice più basso rimanente in arr_r
            k = p;          // Indice di arr in cui inserire il prossimo elemento

            // Popola l'array arr inserendo in ordine gli elementi degli array arr_l e arr_l
            while(i < dim_l && j < dim_r) {
                if(arr_l[i] <= arr_r[j]) {
                    arr[k] = arr_l[i];
                    i++;
                } else {
                    arr[k] = arr_r[j];
                    j++;
                }
                k++;
            }

            // Se l'array arr_r termina prima dell'array arr_l allora copia in ordine gli elementi restanti di arr_l
            while(i < dim_l) {
                arr[k] = arr_l[i];
                i++;
                k++;
            }

            // Se l'array arr_l termina prima dell'array arr_r allora copia in ordine gli elementi restanti di arr_r
            while(j < dim_r) {
                arr[k] = arr_r[j];
                j++;
                k++;
            }
        }
    }
}

void merge_sort(int *arr, int p, int r) {
    int q;

    if(p >= r)                      // Se p >= r allora l'array è vuoto, passo base 
        return;
    
    q = (p + r) / 2;                // Identifica il punto medio di arr[p : q]
    merge_sort(arr, p, q);          // Ordina ricorsivamente l'array arr[p : q]
    merge_sort(arr, q + 1, r);      // Ordina ricorsivamente l'array arr[q + 1 : r]

    merge(arr, p, q, r);            // Fonde gli array arr[p : q] e arr[q + 1 : r]
}