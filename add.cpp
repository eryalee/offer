

#include <stdio.h>


int add(int num1, int num2) {
    do {
        int sum = num1 ^ num2;
        int carray = (num1 & num2) << 1;
        num1 = sum;
        num2 = carray;
    } while (num2 > 0);
    return num1;
}

int main(const int argc, const char *argv[])
{
    printf("add(%d, %d) = %d\n", 8, 9, add(8, 9));  
    printf("add(%d, %d) = %d\n", 800, 0, add(800, 0));  
    return 0;
}
