

#include <stdio.h>

int max_subarray_sum(int A[], int len, bool& flag) {
    flag = false;
    if (NULL == A || len <= 0)  return -1;
    flag = true;
    if (len == 1)  return A[0];

    int max_num = A[0];
    int max_here = A[0];
    for (int i = 1; i < len; ++i) {
        max_here = max_here + A[i] > A[i] ? max_here + A[i] : A[i];
        if (max_here > max_num)  max_num = max_here;
    }
    return max_num;
}

int max_subarray_multi(int A[], int len, bool& flag) {
    flag = false;
    if (NULL == A || len <= 0)  return -1;
    flag = true;
    if (len == 1)  return A[0];
    int max_result = A[0];
    int max_here = 1 * A[0];
    int min_here = 1 * A[0];

    for (int i = 1; i < len; ++i) {
        int cur_max = max_here;
        int cur_min = min_here;
        min_here = cur_min * A[i] < min_here ? cur_min * A[i] : min_here;
        min_here = A[i] < min_here ? A[i] : min_here;
        min_here = cur_max * A[i] < min_here ? cur_max * A[i] : min_here;

        max_here = cur_max * A[i] > max_here ? cur_max * A[i] : max_here;
        max_here = A[i] > max_here ? A[i] : max_here;
        max_here = cur_min * A[i] > max_here ? cur_min * A[i] : max_here;

        if (max_here > max_result)  max_result = max_here;
    }
    return max_result;
}

int main() {
    bool flag = false;
    int A[] = {3, 4, 3, 6, -1, 7, -10, 9, 10};
    printf("max sub array sum = %d\n", max_subarray_sum(A, sizeof(A)/sizeof(A[0]), flag));
    printf("max sub array multiply = %d\n", max_subarray_multi(A, sizeof(A)/sizeof(A[0]), flag));
    int B[] = {-100};
    printf("max sub array sum = %d\n", max_subarray_sum(B, sizeof(B)/sizeof(B[0]), flag));
    printf("max sub array multiply = %d\n", max_subarray_multi(B, sizeof(B)/sizeof(B[0]), flag));
    return 0;
}

