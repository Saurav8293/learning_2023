#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int day;
    int month;
    int year;
} Date;
int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    }
    return 0;
}
int countDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}
int countDaysElapsed(Date date) {
    int totalDays = 0;
    int month;
    for (month = 1; month < date.month; month++) {
        totalDays += countDaysInMonth(month, date.year);
    }
    totalDays += date.day;
    return totalDays;
}
int main() {
    char dateStr[100];
    Date date;
    printf("Enter a date in 'DD/MM/YYYY' format: ");
    fgets(dateStr, sizeof(dateStr), stdin);
    dateStr[strcspn(dateStr, "\n")] = '\0'; 
    sscanf(dateStr, "%d/%d/%d", &date.day, &date.month, &date.year);
    int daysElapsed = countDaysElapsed(date);
    printf("Number of days elapsed: %d\n", daysElapsed);
    return 0;
}
