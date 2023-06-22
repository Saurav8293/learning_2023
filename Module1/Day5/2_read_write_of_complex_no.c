#include <stdio.h>
struct Complex {
    double real;
    double imaginary;
};
void readComplex(struct Complex* num) {
    printf("Enter the real part: ");
    scanf("%lf", &(num->real));
    printf("Enter the imaginary part: ");
    scanf("%lf", &(num->imaginary));
}
void writeComplex(struct Complex num) {
    if (num.imaginary >= 0)
        printf("Complex number: %.2f + %.2fi\n", num.real, num.imaginary);
    else
        printf("Complex number: %.2f - %.2fi\n", num.real, -num.imaginary);
}
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}
struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    result.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return result;
}
int main() {
    struct Complex num1, num2, sum, product;
    printf("Reading Complex Number 1:\n");
    readComplex(&num1);
    printf("\nReading Complex Number 2:\n");
    readComplex(&num2);
    printf("\nWriting Complex Number 1:\n");
    writeComplex(num1);
    printf("\nWriting Complex Number 2:\n");
    writeComplex(num2);
    sum = addComplex(num1, num2);
    printf("\nSum of Complex Numbers:\n");
    writeComplex(sum);
    product = multiplyComplex(num1, num2);
    printf("\nProduct of Complex Numbers:\n");
    writeComplex(product);
    return 0;
}