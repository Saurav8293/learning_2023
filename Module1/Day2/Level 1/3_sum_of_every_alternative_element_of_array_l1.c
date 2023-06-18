#include <stdio.h>
int main() {
    int arr_size;
    scanf("%d",&arr_size);
    int arr[arr_size];
    for(int i=0;i<arr_size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < arr_size; i += 2) {
        sum += arr[i];
    }
    printf("Sum of every alternate element: %d", sum);
    return 0;
}
