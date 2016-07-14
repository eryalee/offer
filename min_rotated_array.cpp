
#include <stdio.h>

int min_in_order(int A[], int start, int end) {
    int result = A[start];
    for (int i = start + 1; i <= end; ++i) {
        if (result > A[i])  result = A[i];
    }
    return result;
}

int min_rotated_array(int A[], int len) {
    if (NULL == A || len <= 0)  return -1;
    if (len == 1)  return A[0];
    if (len == 2)  return A[0] > A[1] ? A[1] : A[0];

    int start = 0;
    int end = len - 1;
    int mid = start;
    while (A[start] >= A[end]) {
        if (end - start == 1)  {
            mid = end;
            break;
        }
        mid = start + (end - start)/2;
        if (A[mid] == A[start] && A[mid] == A[end]) {
            return min_in_order(A, start, end);
        }
        if (A[mid] >= A[start]) {
            start = mid;
        } else if (A[mid >= A[end]]) {
            end = mid;
        }
    }
    return A[mid];
}

int main() {
    int A[] = {4,5,6,1,2};
    printf("find min = %d\n", min_rotated_array(A, sizeof(A)/sizeof(A[0])));
    int B[] = {4,5,6, 10, -100, -11,0,2};
    printf("find min = %d\n", min_rotated_array(B, sizeof(B)/sizeof(B[0])));
    int C[] = {2};
    printf("find min = %d\n", min_rotated_array(C, sizeof(C)/sizeof(C[0])));
    int D[] = {2, 2, 2, 2, 0, 2};
    printf("find min = %d\n", min_rotated_array(D, sizeof(D)/sizeof(D[0])));
    return 0;
}
