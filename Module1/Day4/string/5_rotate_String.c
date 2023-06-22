#include <stdio.h>
#include <string.h>
void rotateString(char* str, int k, char direction) {
    int len = strlen(str);
    char temp;
    if (direction == 'L' || direction == 'l') {
        while (k > 0) {
            temp = str[0];
            memmove(str, str + 1, len - 1);
            str[len - 1] = temp;
            k--;
        }
    }
    else if (direction == 'R' || direction == 'r') {
        while (k > 0) {
            temp = str[len - 1];
            memmove(str + 1, str, len - 1);
            str[0] = temp;
            k--;
        }
    }
}
int main() {
    char str[50];
    int k;
    char direction;
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);
    printf("Enter the direction (L for Left, R for Right): ");
    scanf(" %c", &direction);
    rotateString(str, k, direction);
    printf("Rotated string: %s\n", str);    
    return 0;
}