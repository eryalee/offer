#include <stdio.h>
#include <limits.h>

bool g_valid = false;
int string2int(const char *str) {
    if (NULL == str || *str == '\0') {
        printf("return 1\n");
        return 0;
    }
    const char *p = str;
    while (*p == ' ')  ++p;
    bool minus = false;
    if (*p == '-' || *p == '+') {
        if (*p == '-')  minus = true;
        ++p;
    }

    int result = 0;
    while (*p != '\0') {
        if (*p < '0' || *p > '9') {
            result = 0;
            printf("return 2\n");
            break;
        }
        int num = *p - '0';
        if (!minus) {
            if ((INT_MAX - num)/10 < result) {
                printf("return 3, INT_MAX = %d num = %d, result = %d\n", INT_MAX, num, result);
                result = 0;
                break;
            }
        } else {
            if ((INT_MIN + num)/10 > -result) {
                printf("return 4, INT_MIN = %d num = %d, result = %d\n", INT_MIN, num, -result);
                result = 0;
                break;
            }
        }
        result = result * 10 + num;
        ++p;
    }

    if (*p == '\0')  g_valid = true;
    return minus ? -result : result;
}

int main(const int argc, const char *argv[])
{
    printf("result = %d\n", string2int("999999"));
    printf("result = %d\n", string2int(""));
    printf("result = %d\n", string2int("-1010101335"));
    printf("result = %d\n", string2int("+1010101335"));
    printf("result = %d\n", string2int("-"));
    printf("result = %d\n", string2int("+2147483647"));
    printf("result = %d\n", string2int("-2147483648"));
    return 0;
}
