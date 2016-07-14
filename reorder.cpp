
#include <stdio.h>

void reorder(int *p_data, int len, bool (*func)(int)) {
    if (NULL == p_data || len <= 0)  return;
    int start = 0;
    int end = len - 1;
    while (start < end) {
        while (start < end && !fuc(p_data[start]))  start++;
        while (start < end && func(p_data[end]))  end--;
        if (start < end) {
            swap(p_data[start], p_data[end]);
        }
    }
}

int main() {
    return 0;
}
