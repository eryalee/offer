
#include <stdio.h>
#include <limits.h>
int peek_element(int A[], int len) {
    if (NULL == A || len <= 0)  return -1;
    if (len == 1)  return 0;
    if (len == 2)  return A[0] >= A[1] ? 0 : 1;
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        int left_value = mid > 0 ? A[mid - 1] : INT_MIN;
        int right_value = mid < len - 1 ? A[mid + 1] : INT_MIN;
        if (left_value <= A[mid] && A[mid] >= right_value)  return mid;
        else if (A[left] <= A[mid - 1] && A[mid - 1] >= A[mid])  right = mid - 1;
        else left = mid + 1;
    }
}

int main(const int argc, const char *argv[])
{
    int A[] = {2};
    int B[] = {};
    int C[] = {2, 5};
    int D[] = {2, 5, 3, 4, 5, 6, 4, 2};
    int E[] = {2, 5, 3, 4, 6, 6, 6, 6};
    printf("peek index = %d\n", peek_element(A, 1));  
    printf("peek index = %d\n", peek_element(B, 0));  
    printf("peek index = %d\n", peek_element(C, 2));  
    printf("peek index = %d\n", peek_element(D, sizeof(D)/sizeof(D[0])));  
    printf("peek index = %d\n", peek_element(E, sizeof(E)/sizeof(E[0])));  
    return 0;
}
