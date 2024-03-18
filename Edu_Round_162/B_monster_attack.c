#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int health, position;
    int dist;
} monster_arr_t;

void merge(monster_arr_t *arr, int p, int q, int r);
void merge_sort(monster_arr_t *arr, int p, int r);

int main() {
    int n_tests, test, turn;
    int n_monsters, n_bullets, bullets_tmp, is_alive;
    monster_arr_t *monsters;

    int i, j;

    scanf("%d", &n_tests);
    for(test = 0; test < n_tests; test++) {
        scanf("%d %d", &n_monsters, &n_bullets);
        monsters = malloc(sizeof(monster_arr_t) * n_monsters);
        for(i = 0; i < n_monsters; i++)
            scanf("%d", &monsters[i].health);
        for(i = 0; i < n_monsters; i++) {
            scanf("%d", &monsters[i].position);
            if(monsters[i].position >= 0)
                monsters[i].dist = monsters[i].position;
            else
                monsters[i].dist = - monsters[i].position;
        }

        merge_sort(monsters, 0, n_monsters - 1); // Sorting by distance of the monster from the player

        is_alive = 1;
        i = 0;
        turn = 0;
        while(is_alive && i < n_monsters) {
            bullets_tmp = n_bullets;
            turn++;
            j = i;
            while(bullets_tmp > 0 && i < n_monsters) {
                if(bullets_tmp >= monsters[i].health) {
                    bullets_tmp -= monsters[i].health;
                    i++;
                } else {
                    monsters[i].health -= bullets_tmp;
                    bullets_tmp = 0;
                }
            }
            if(i == j) {
                monsters[i].dist -= 1;
            } else {
                monsters[i].dist -= turn;
                j = i;
            }
            if(monsters[i].dist <= 0)
                is_alive = 0;
        }
        if(is_alive)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

void merge(monster_arr_t *arr, int p, int q, int r) {
    int dim_l, dim_r;
    monster_arr_t *arr_l, *arr_r;
    int i, j, k;

    dim_l = q - p + 1;      // Lunghezza di arr[p : q]
    dim_r = r - q;          // lunghezza di arr[q + 1 : r]
    
    arr_l = malloc(sizeof(monster_arr_t) * dim_l);
    if(arr_l) {
        arr_r = malloc(sizeof(monster_arr_t) * dim_r);
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
                if(arr_l[i].dist <= arr_r[j].dist) {
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

void merge_sort(monster_arr_t *arr, int p, int r) {
    int q;

    if(p >= r)                      // Se p >= r allora l'array è vuoto, passo base 
        return;
    
    q = (p + r) / 2;                // Identifica il punto medio di arr[p : q]
    merge_sort(arr, p, q);          // Ordina ricorsivamente l'array arr[p : q]
    merge_sort(arr, q + 1, r);      // Ordina ricorsivamente l'array arr[q + 1 : r]

    merge(arr, p, q, r);            // Fonde gli array arr[p : q] e arr[q + 1 : r]
}