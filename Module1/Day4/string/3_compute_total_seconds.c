#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TIME_DELIMITER ":"
unsigned long computeTotalSeconds(const char *timeStr) {
    char *token;
    unsigned long hours, minutes, seconds;
    token = strtok((char *)timeStr, TIME_DELIMITER);
    hours = strtoul(token, NULL, 10);
    token = strtok(NULL, TIME_DELIMITER);
    minutes = strtoul(token, NULL, 10);
    token = strtok(NULL, TIME_DELIMITER);
    seconds = strtoul(token, NULL, 10);
    unsigned long totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
    return totalSeconds;
}
int main() {
    char timeStr[100];
    printf("Enter time in 'hh:mm:ss' format: ");
    fgets(timeStr, sizeof(timeStr), stdin);
    timeStr[strcspn(timeStr, "\n")] = '\0';  
    unsigned long totalSeconds = computeTotalSeconds(timeStr);
    printf("Total Seconds: %lu\n", totalSeconds);
    return 0;
}
