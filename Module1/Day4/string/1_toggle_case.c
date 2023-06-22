#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100
void toggleCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}
int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 
    printf("Input String: %s\n", str);
    toggleCase(str);
    printf("Output String: %s\n", str);
    return 0;
}