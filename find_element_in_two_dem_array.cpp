

#include <stdio.h>

int find(int *matrix, int rows, int columns, int number) {
    bool found = false;
    if (NULL != matrix && rows > 0 && columns > 0) {
        int top = 0;
        int right = columns - 1;
        while (top < rows && right >= 0) {
            if (matrix[columns * top + right] == number) {
                found = true;
                break;
            } else if (matrix[columns * top + right] > number) {
                right--;
            } else {
                top++;
            }
        }
    }
    return found;
}

int main() {
    int matrix[] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
    printf("found(%d) = %d\n", 7, find(matrix, 4, 4, 7));
    printf("found(%d) = %d\n", 16, find(matrix, 4, 4, 16));
    printf("found(%d) = %d\n", -1, find(matrix, 4, 4, -1));
    return 0;
}
