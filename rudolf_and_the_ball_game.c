/*
Data una lista, rappresentante i giocatori che possono avere la palla in un determinato turno, avente all'inizio un solo elemento, ad ogni turno, per ogni
giocatore possibile, si effettua la transizione della palla ad un altro giocatore, nel caso in cui non è specificata la direzione di questa si proveranno entrambi
i casi
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct player_ {
    int id, turn;
    struct player_ *next;
} player_t;

player_t* add_last(player_t *player, int id, int turn, int *added);
void merge(int *arr, int p, int q, int r);
void merge_sort(int *arr, int p, int r);

int main() {
    int test_cases, n_players, n_turns, id_first;
    int test, turn;
    int distance, id1, id2, dim_players, added;
    char direction;
    int *players_id, i;
    player_t *players = NULL, *tmp;

    scanf("%d", &test_cases);
    for(test = 0; test < test_cases; test++) {
        scanf("%d %d %d", &n_players, &n_turns, &id_first);

        // Inserisce il primo giocatore nella lista, è deterministico, all'inizio (turno 0) un solo giocatore può avere la palla
        players = add_last(players, id_first, 0, &added);
        dim_players = 1;

        // Per ogni turno scorre la lista dei giocatori e per ogni giocatore effettua tutte le possibili transizioni (1 o 2), aggiunge alla lista il giocatore
        // che può avere la palla a seguito di quella transizione insieme al turno in cui è stata eseguita e rimuove il giocatore da cui la transizione è
        // partita. Salvando il turno nella lista è possibile sapere quando passare al turno successivo
        for(turn = 1; turn <= n_turns; turn++) {
            scanf("%d %c", &distance, &direction);
            if(direction == '0') {            // Senso orario
                while(players->turn < turn) {
                    id1 = (players->id + distance) % n_players;
                    if(id1 == 0)
                        id1 = n_players;
                    players = add_last(players, id1, turn, &added);
                    if(added)
                        dim_players++;
                    tmp = players;
                    players = players->next;
                    free(tmp);
                    dim_players--;
                }
            } else if(direction == '1') {     // Senso antiorario
                while(players->turn < turn) {
                    id1 = (players->id + n_players - distance) % n_players;
                    if(id1 == 0)
                        id1 = n_players;
                    players = add_last(players, id1, turn, &added);
                    if(added)
                        dim_players++;
                    tmp = players;
                    players = players->next;
                    free(tmp);
                    dim_players--;
                }
            } else if(direction == '?') {   // Senso non specificato (due possibili strade)
                while(players->turn < turn) {
                    id1 = (players->id + distance) % n_players;
                    if(id1 == 0)
                        id1 = n_players;
                    players = add_last(players, id1, turn, &added);
                    if(added)
                        dim_players++;
                    id2 = (players->id + n_players - distance) % n_players;
                    if(id2 == 0)
                        id2 = n_players;
                    players = add_last(players, id2, turn, &added);
                    if(added)
                        dim_players++;
                    tmp = players;
                    players = players->next;
                    free(tmp);
                    dim_players--;
                }
            }
        }
        printf("%d\n", dim_players);
        players_id = malloc(sizeof(int) * dim_players);
        for(tmp = players, players = players->next, i = 0; players; tmp = players, players = players->next, i++) {
            players_id[i] = tmp->id;
            free(tmp);
        }
        players_id[i] = tmp->id;
        free(tmp);
        
        merge_sort(players_id, 0, dim_players - 1);
        for(i = 0; i < dim_players; i++)
            printf("%d ", players_id[i]);
        printf("\n");
        free(players_id);
    }

    return 0;
}

player_t* add_last(player_t *player, int id, int turn, int *added) {
    player_t *curr, *tmp;
    int valid;

    tmp = malloc(sizeof(player_t));
    if(tmp) {
        tmp->id = id;
        tmp->turn = turn;
        tmp->next = NULL;

        if(!player) {
            player = tmp;
        } else {
            for(curr = player, valid = 1; valid && curr && curr->next; curr = curr->next)
                if(curr->id == id && curr->turn == turn) {
                    valid = 0;
                }

            if(valid && (curr->id != id || curr->turn != turn)) {
                curr->next = tmp;
                *added = 1;
            } else {
                *added = 0;
            }
        }
    }
    return player;
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