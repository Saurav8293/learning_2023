#include <stdio.h>
void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}
int main() {
    int x = 25, y = 30;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swapping: x = %d, y = %d\n", x, y);
    float a = 4.15, b = 5.61;
    printf("Before swapping: a = %f, b = %f\n", a, b);
    swap(&a, &b, sizeof(float));
    printf("After swapping: a = %f, b = %f\n", a, b);   
    char c1 = 'C', c2 = 'D';
    printf("Before swapping: c1 = %c, c2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("After swapping: c1 = %c, c2 = %c\n", c1, c2);
    return 0;
}