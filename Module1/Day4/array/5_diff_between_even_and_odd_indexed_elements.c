#include <stdio.h>
#define MAX_SIZE 10
int main() {
    int arr[MAX_SIZE];
    int len, i;
    int sum_even = 0, sum_odd = 0;
    int diff;
    printf("Enter the length of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &len);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            sum_even += arr[i];
        } else {
            sum_odd += arr[i];
        }
    }
    diff = sum_even - sum_odd;
    printf("Difference between the sum of even-indexed and odd-indexed elements: %d\n", diff);
    printf("Sum of even-indexed elements: %d\n", sum_even);
    printf("Sum of odd-indexed elements: %d\n", sum_odd);
    return 0;
}
