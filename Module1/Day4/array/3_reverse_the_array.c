#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int arr[MAX_SIZE];
    int len, i, temp;
    printf("Enter the length of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &len);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < len / 2; i++) {
        temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
    printf("Reversed array: ");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}