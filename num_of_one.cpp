
#include <stdio.h>

int num_of_one(int num) {
    int total = 0;
    while (num != 0) {
        if (num & 1)  ++total;
        num >>= 1;
    }
    return total;
}

int main() {
    printf("num_of_one(%d) = %d\n", 10, num_of_one(10));
    printf("num_of_one(%d) = %d\n", 0, num_of_one(0));
    printf("num_of_one(%d) = %d\n", -10, num_of_one(-10));
    return 0;
}
