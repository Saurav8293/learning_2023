#include <stdio.h>
#define MAX_SIZE 10
int main() {
    int arr[MAX_SIZE];
    int len, i;
    int min, max;
    printf("Enter the length of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &len);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    min = max = arr[0];
    for (i = 1; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    return 0;
}
