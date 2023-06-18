#include <stdio.h>
void swap_elements(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}
void print_array(int arr[], int size) {
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr_size;
    scanf("%d",&arr_size);
    int arr[arr_size];
    for(int i=0;i<arr_size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Original Array: ");
    print_array(arr, arr_size);
    printf("Resulting Array: ");
    swap_elements(arr, arr_size);
    print_array(arr, arr_size);
    return 0;
}
