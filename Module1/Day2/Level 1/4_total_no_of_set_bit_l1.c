#include <stdio.h>
int countsetbits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);
    int totalsetbits = 0;
    for (int i = 0; i < size; i++) {
        totalsetbits += countsetbits(arr[i]);
    }
    printf("The total number of set bits in the given array is: %d\n", totalsetbits);
    return 0;
}