
#include <stdio.h>


int max_subarray(int A[], int len) {
    if (NULL == A || len <= 0) {
        return 0;
    }
    int max_value = A[0];
    int cur_max_value = max_value;
    for (int i = 1; i < len; ++i) {
        cur_max_value = (cur_max_value + A[i] >= A[i] ? cur_max_value + A[i] : A[i]);
        if (cur_max_value > max_value)  max_value = cur_max_value;
    }
    return max_value;
}
int main(const int argc, const char *argv[])
{
    int A[] = {1, -2, 3 , 10, -4, 7, 2, -5};
    printf("maxvalue = %d\n", max_subarray(A, sizeof(A)/sizeof(A[0])));
    return 0;
}
