#include<stdio.h>
#include<stdlib.h>

typedef struct player_ {
    int id, turn;
    struct player_ *next;
} state_t;

state_t* add_last(state_t *player, int id);

int main() {
    int test, n_tests;
    int verts, **edges, i, u, v, *leafs;
    int max, stato;
    state_t *states = NULL;

    scanf("%d", &n_tests);
    for(test = 0; test < n_tests; test++) {
        scanf("%d", &verts);

        *edges = malloc(sizeof(int*) * (verts + 1));
        for(i = 0; i < verts; i++)
            edges[i] = malloc(sizeof(int) * (verts + 1));
        *leafs = malloc(sizeof(int) * (verts + 1));

        for(i = 1; i <= verts; i++)
            leafs[i] = 0;

        for(i = 0; i < verts - 1; i++) {
            scanf("%d %d", &u, &v);
            edges[u][v] = edges[v][u] = 1;
            leafs[u] += 1;
            leafs[v] += 1;
        }

        for(i = 1, max = leafs[1], stato = 1; i <= verts; i++)
            if(leafs[i] > max) {
                max = leafs[i];
                stato = i;
            }

        states = add_last(states, stato);
        while(states) {
            printf("%d %d", states->id, 1);
        }
        
    }

    return 0;
}

state_t* add_last(state_t *player, int id) {
    state_t *curr, *tmp;
    int valid;

    tmp = malloc(sizeof(state_t));
    if(tmp) {
        tmp->id = id;
        tmp->next = NULL;

        if(!player) {
            player = tmp;
        } else {
            for(curr = player, valid = 1; valid && curr && curr->next; curr = curr->next)
                if(curr->id == id) {
                    valid = 0;
                }

            if(valid && (curr->id != id)) {
                curr->next = tmp;
            }
        }
    }
    return player;
}