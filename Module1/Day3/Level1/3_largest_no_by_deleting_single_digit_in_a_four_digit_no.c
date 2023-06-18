#include <stdio.h>
int findLargestNumber(int num) {
    int largest = 0;
    int divisor = 1;
    while (divisor <= 1000) {
        int currentNum = (num / (divisor * 10)) * divisor + (num % divisor);
        if (currentNum > largest) {
            largest = currentNum;
        }
        divisor *= 10;
    }
    return largest;
}
int main() {
    int number;
    printf("Enter a 4-digit number: ");
    scanf("%d", &number);
    if (number < 1000 || number > 9999) {
        printf("Invalid input. Please enter a 4-digit number.\n");
        return 0;
    }
    int largestNumber = findLargestNumber(number);
    printf("The largest number after deleting a single digit: %d\n", largestNumber);
    return 0;
}