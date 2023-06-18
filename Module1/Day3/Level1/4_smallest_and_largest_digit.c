#include <stdio.h>
#include <stdarg.h>

void findMinMaxDigits(int n, ...) {
    int num, smallest = 9, largest = 0;
    int i, digit;

    va_list args;
    va_start(args, n);

    for (i = 0; i < n; i++) {
        num = va_arg(args, int);

        while (num > 0) {
            digit = num % 10;

            if (digit < smallest) {
                smallest = digit;
            }

            if (digit > largest) {
                largest = digit;
            }

            num /= 10;
        }
    }

    va_end(args);

    if (smallest == 9 || largest == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallest);
        printf("Largest Digit: %d\n", largest);
    }
}

int main() {
    findMinMaxDigits(3, 8, 156, 123450);

    return 0;
}
