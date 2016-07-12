#include <stdio.h>

/*
 * @brief: 原地替换空格
 */
void replace_blank(char str[], int len) {
    if (NULL == str || len <= 0)  return;
    int origin_len = 0;
    int number_of_blank = 0;
    while (str[origin_len] != '\0') {
        if (str[origin_len] == ' ') {
            number_of_blank++;
        }
        ++origin_len;
    }
    if (0 == number_of_blank)  return;
    int new_len = origin_len + 2 * number_of_blank;
    if (len <= new_len)  return;

    int new_forward_index = new_len + 1;
    str[new_forward_index--] = '\0';
    while (origin_len >= 0) {
        if (str[origin_len] == ' ') {
            str[new_forward_index--] = '0';
            str[new_forward_index--] = '2';
            str[new_forward_index--] = '%';
        } else {
            str[new_forward_index--] = str[origin_len];
        }
        origin_len--;
    }
    return;
}

int main() {
    static const int len = 100;
    char *str = new char[len];
    snprintf(str, len, "%s", "http not found!");
    printf("before replace str = %s\n", str);
    replace_blank(str, len);
    printf("after replace str = %s\n", str);

    snprintf(str, len, "%s", "httpFounded!");
    printf("before replace str = %s\n", str);
    replace_blank(str, len);
    printf("after replace str = %s\n", str);

    snprintf(str, len, "%s", " ");
    printf("before replace str = %s\n", str);
    replace_blank(str, len);
    printf("after replace str = %s\n", str);

    char *p = NULL;
    replace_blank(p, len);
    //printf("after replace str = %s\n", str);
    return 0;
}
