#include <stdio.h>

int gas_station(int gas[], int dis[], int len) {
    if (NULL == gas || NULL == dis || len <= 0) {
        return -1;
    }
    int cur_gas = 0;
    int total_gas = 0;
    int idx = 0;
    int start_idx = 0;
    while (idx < len) {
        total_gas += gas[idx] - dis[idx];
        cur_gas += gas[idx];
        if (cur_gas < dis[idx]) {
            start_idx = idx + 1;
            cur_gas = 0;
        } else {
            cur_gas -= dis[idx];
        }
        ++idx;
    }
    if (total_gas >= 0 && cur_gas >= 0 && start_idx < len) {
        return start_idx;
    }
    return -1;
}

int main(const int argc, const char *argv[])
{
    int gas1[] = {5, 5, 5, 5};
    int dis1[] = {4, 3, 2, 4};
    printf("start idx = %d\n", gas_station(gas1, dis1, 4));
    int gas2[] = {5, 1, 5, 5};
    int dis2[] = {4, 3, 2, 4};
    printf("start idx = %d\n", gas_station(gas2, dis2, 4));
    int gas3[] = {5, 1, 1, 2};
    int dis3[] = {4, 3, 2, 4};
    printf("start idx = %d\n", gas_station(gas3, dis3, 4));
    int gas4[] = {2, 4};
    int dis4[] = {3, 4};
    printf("start idx = %d\n", gas_station(gas4, dis4, 2));
    return 0;
}
