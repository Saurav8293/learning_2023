#include <stdio.h>
void exponent_part(double x) {
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;
    printf("Hexadecimal exponent: 0x%llx\n", exponent);
    unsigned long long binaryExponent = 0;
    int i;
    for (i = 10; i >= 0; i--) {
        binaryExponent |= ((exponent >> i) & 1) << (10 - i);
    }
    printf("Binary exponent: 0b");
    for (i = 10; i >= 0; i--) {
        printf("%llu", (binaryExponent >> i) & 1);
    }
    printf("\n");
}
int main() {
    double x = 0.2;
    exponent_part(x);
    return 0;
}
