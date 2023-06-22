#include <stdio.h>
#define MAX_SIZE 10
int main() {
    int arr[MAX_SIZE];
    int len, i;
    int sum = 0;
    float avg;
    printf("Enter the length of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &len);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < len; i++) {
        sum += arr[i];
    }
    avg = (float)sum / len;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    return 0;
}
