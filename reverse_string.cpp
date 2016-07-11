
#include <stdio.h>
#include <string.h>

void reverse(char *begin, char *end) {
    if (NULL == begin || NULL == end) {
        return;
    }
    while (begin < end) {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        ++begin;
        --end;
    }
    return;
}

void reverse_sentences(char *sentence) {
    if (NULL == sentence) {
        return;
    }
    int len = strlen(sentence);
    if (len <= 0) {
        return;
    }

    char *begin = sentence;
    char *end = sentence + len - 1;
    reverse(begin, end);
    begin = sentence;
    end = sentence;
    while (*begin != '\0') {
        if (*begin == ' ') {
            ++begin;
            ++end;
        } else if (*end == ' ' || *end == '\0') {
            reverse(begin, --end);
            begin = ++end;
        } else {
            ++end;
        }
    }
}

char *left_rotate_string(char *src, int n) {
    if (NULL == src)  return NULL;
    int len = strlen(src);
    if (len == 0 || n <= 0 || n >= len)  return src;
    char *begin = src;
    char *mid = src + n - 1;
    reverse(begin, mid);
    mid = src + n;
    char *end = src + len - 1;
    reverse(mid, end);
    begin = src;
    end = src + len - 1;
    reverse(begin, end);
    return src;
}

int main(const int argc, const char *argv[])
{
    char A[] = "i am a student.";
    printf("A == %s\n", A);
    reverse_sentences(A);
    printf("A == %s\n", A);
    char B[] = "";
    printf("B == %s\n", B);
    reverse_sentences(B);
    printf("B == %s\n", B);
    char *C = NULL;
    reverse_sentences(C);
    char D[] = "E";
    printf("D == %s\n", D);
    reverse_sentences(D);
    printf("D == %s\n", D);

    char E[] = "abcdefghi";
    printf("E == %s\n", E);
    printf("rotate E = %s\n", left_rotate_string(E, 4));
    return 0;
}
