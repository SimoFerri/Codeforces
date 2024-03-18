#include<stdio.h>

int main() {
    int position, n_houses, n_tasks;
    int i, house, task;
    long long int time;

    scanf("%d %d", &n_houses, &n_tasks);
    for(task = 0, position = 1, time = 0; task < n_tasks; task++) {
        scanf("%d", &house);
        if(house > position)
            time += house - position;
        else if(house < position)
            time += n_houses - (position - house);
        position = house;
    }
    printf("%lld\n", time);

    return 0;
}
