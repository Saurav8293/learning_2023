#include <stdio.h>
struct Time {
    int hours;
    int minutes;
    int seconds;
};
void getTimePeriod(struct Time* time) {
    printf("Enter the time period (hours minutes seconds): ");
    scanf("%d %d %d", &(time->hours), &(time->minutes), &(time->seconds));
}
void calculateDifference(struct Time time1, struct Time time2, struct Time* difference) {
    int totalSeconds1 = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
    int totalSeconds2 = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;
    int diffSeconds = totalSeconds2 - totalSeconds1;
    difference->hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    difference->minutes = diffSeconds / 60;
    difference->seconds = diffSeconds % 60;
}
void displayTimePeriod(struct Time time) {
    printf("%02d:%02d:%02d\n", time.hours, time.minutes, time.seconds);
}
int main() {
    struct Time time1, time2, difference;
    printf("Enter the first time period:\n");
    getTimePeriod(&time1);
    printf("\nEnter the second time period:\n");
    getTimePeriod(&time2);
    calculateDifference(time1, time2, &difference);
    printf("\nDifference between the time periods:\n");
    displayTimePeriod(difference);
    return 0;
}