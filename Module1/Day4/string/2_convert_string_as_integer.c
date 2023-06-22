#include <stdio.h>
int stringToInteger(const char *str) {
    int res = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            int ival = str[i] - '0';
            res = res * 10 + ival;
        }
        i++;
    }
    return res;
}
int main() {
    char str[100];
    printf("Enter a string of digits: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 
    int value = stringToInteger(str);
    printf("Converted Integer: %d\n", value);
    return 0;
}