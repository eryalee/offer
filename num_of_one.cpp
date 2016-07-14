
#include <stdio.h>

int num_of_one(int num) {
    int total = 0;
    int move_num = 0;
    while (num != 0) {
        if (move_num == 32)  break;
        if (num & 1)  ++total;
        num >>= 1;
        move_num++;
    }
    return total;
}
int count_one(int num) {
    int x = num;
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
}

int num_of_one1(int num) {
    int count = 0;
    while (num) {
        ++count;
        num &= (num - 1);
    }
    return count;
}

int main() {
    printf("num_of_one(%d) = %d\n", 10, num_of_one(10));
    printf("num_of_one(%d) = %d\n", 0, num_of_one(0));
    printf("num_of_one(%d) = %d\n", -10, num_of_one(-10));
    printf("num_of_one(%d) = %d\n", -10, count_one(-10));
    printf("num_of_one(%d) = %d\n", -10, num_of_one1(-10));
    printf("num_of_one(%d) = %d\n", 10, count_one(10));
    return 0;
}
