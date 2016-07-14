#include <stdio.h>

int partition(int A[], int start, int end) {
    if (NULL == A || start < 0 || end < 0 || start >= end)  return start;

    int idx = start + 1;
    int last_small = start;
    while (idx <= end) {
        if (A[idx] < A[start]) {
            int temp = A[++last_small];
            A[last_small] = A[idx];
            A[idx] = temp;
        }
        idx++;
    }
    int temp = A[start];
    A[start] = A[last_small];
    A[last_small] = temp;
    return last_small;
}

void print(int A[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d,", A[i]);
    }
    printf("\n");
}


void quick_sort(int A[], int start, int end) {
    if (NULL == A || end - start <= 1)  return;
    int idx = partition(A, start, end);
    if (idx > start) {
        quick_sort(A, start, idx - 1);
    }
    if (idx < end) {
        quick_sort(A, idx + 1, end);
    }
}

int main() {
    int A[] = {7, 5, 6, 3, 9, 10, 15, -4};
    print(A, sizeof(A)/sizeof(A[0]));
    /*
    partition(A, 0, sizeof(A)/sizeof(A[0]));
    */

    quick_sort(A, 0, sizeof(A)/sizeof(A[0]) - 1); 
    print(A, sizeof(A)/sizeof(A[0]));

    return 0;
}
