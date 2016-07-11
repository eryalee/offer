
#include <stdio.h>
int lower_bound(int A[], int length, int target) {
    if (NULL == A || length <= 0) {
        printf("are u return?\n");
        return -1;
    }
    int left = 0;
    int right = length - 1;
    
    while (left < right) {
        int mid = left + (right - left)/2;
        if (A[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int res = -1;

    if (left >= 0 && left < length && A[left] == target)  res = left;
    return res;
}

int main(const int argc, const char *argv[])
{

    int A[] = {1,4,6,7,9,10};
    printf("A length = %lu\n", sizeof(A)/sizeof(A[0]));
    printf("res = %d\n", lower_bound(A, sizeof(A)/sizeof(int), 9));
    printf("res = %d\n", lower_bound(A, sizeof(A)/sizeof(int), -9));
    int B[] = {-100, -50, -50, -50,-50, 0, 10, 10, 90, 1000};
    printf("res = %d\n", lower_bound(B, sizeof(B)/sizeof(int), -50));
    printf("res = %d\n", lower_bound(B, sizeof(B)/sizeof(int), 10));
    printf("res = %d\n", lower_bound(B, sizeof(B)/sizeof(int), 500));
    int C[] = {3};
    printf("res = %d\n", lower_bound(C, sizeof(C)/sizeof(int), 1));
    printf("res = %d\n", lower_bound(C, sizeof(C)/sizeof(int), 3));
    printf("res = %d\n", lower_bound(C, sizeof(C)/sizeof(int), 4));
    return 0;
}
