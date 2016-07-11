
#include <stdio.h>

void print_sequence(int small, int big) {
    for (int i = small; i <= big; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}

void continue_sequence(int sum) {
    if (sum < 3)  return;
    int small = 1;
    int big = 2;
    int mid = (sum + 1)/2;
    int cur_sum = small + big;
    while (small < mid) {
        if (cur_sum == sum) {
            print_sequence(small, big);
        }
        while (cur_sum > sum && small < mid) {
            cur_sum -= small;
            small++;
            if (cur_sum == sum)  print_sequence(small, big);
        }
        big++;
        cur_sum += big;
    }
    return;
}

void cq(int sum) {
    if (sum < 3)  return;
    int small = 1;
    int big = 2;
    int mid = (sum + 1)/2;
    int cur_sum = small + big;
    while (small < mid) {
        if (cur_sum == sum) {
            print_sequence(small, big);
        }
        while (cur_sum > sum && small < mid) {
            cur_sum -= small;
            small++;
            if (cur_sum == sum)  print_sequence(small, big);
        }
        big++;
        cur_sum += big;
    }
    return;
}

int main(const int argc, const char *argv[])
{
    printf("******************************\n");
    continue_sequence(9);   
    printf("******************************\n");
    continue_sequence(0);   
    printf("******************************\n");
    continue_sequence(3);   
    printf("******************************\n");
    continue_sequence(4);   
    printf("******************************\n");
    continue_sequence(101);   
    printf("******************************\n");
    continue_sequence(30000);   
    printf("******************************\n");
    return 0;
}
