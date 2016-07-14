
#include <stdio.h>
#include <string.h>

void print(char *number) {
    bool first_nonzero = false;
    int len = strlen(number);
    for (int i = 0; i < len; ++i) {
        if (!first_nonzero && number[i] != '0') {
            first_nonzero = true;
        }
        if (first_nonzero) {
            printf("%c", number[i]);
        }
    }
    printf("\n");
}

void print_1_to_max_of_ndigit_recursively(char *number, int len, int idx) {
    if (idx == len - 1) {
        print(number);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        number[idx + 1] = i + '0';
        print_1_to_max_of_ndigit_recursively(number, len, idx + 1);
    }
}

void print_1_to_max_of_ndigit(int n) {
    if (n <= 0)  return;
    char *number = new char[n + 1];
    number[n] = '\0';
    for (int i = 0; i < 10; ++i) {
        number[0] = i + '0';
        print_1_to_max_of_ndigit_recursively(number, n, 0);
    }
    delete []number;
}


int main() {
    print_1_to_max_of_ndigit(2);
}
