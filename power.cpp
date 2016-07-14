
#include <stdio.h>

bool g_invalid = false;
bool equal(double base, double target) {
    if (base - target < 0.000001 && target - base < 0.000001)
        return true;
    return false;
}

double PowWithUnsignedExp(double base, unsigned int exp) {
    if (exp == 0)  return 1.0;
    if (exp == 1)  return base;
    double result = PowWithUnsignedExp(base, exp>>1);
    result *= result;
    if (exp & 0x1) result *= base;
    return result;
    /*
    double result = 1.0;
    for (unsigned int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
    */
}
double Pow(double base, int exponent) {
    if (equal(base, 0.0) && exponent < 0) {
        g_invalid = true;
        return 0.0;
    }
    unsigned int abs_exp = (unsigned int)exponent;
    if (exponent < 0) {
        abs_exp = (unsigned int)(-exponent);
    }
    double result = PowWithUnsignedExp(base, abs_exp);
    if (exponent < 0) {
        result = 1.0/result;
    }
    return result;
    
}

int main() {
    printf("pow(%.2lf,%d) = %.2lf\n", 2.0, 3, Pow(2.0, 3));
    printf("pow(%.2lf,%d) = %.22lf\n", 22.0, -3, Pow(22.0, -3));
    printf("pow(%.2lf,%d) = %.22lf\n", 2.0, 102, Pow(2.0, 102));
    return 0;
}
