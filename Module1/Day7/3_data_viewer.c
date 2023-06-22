#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100
struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};
void extractLogData(const char* filePath, struct LogEntry* logEntries, int* numEntries) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Unable to open file. Exiting...\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    char* token;
    int lineCount = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (lineCount == 0) {
            lineCount++;
            continue;
        }
        token = strtok(line, ",");
        logEntries[lineCount - 1].entryNo = atoi(token);
        token = strtok(NULL, ",");
        strncpy(logEntries[lineCount - 1].sensorNo, token, sizeof(logEntries[lineCount - 1].sensorNo));
        token = strtok(NULL, ",");
        logEntries[lineCount - 1].temperature = atof(token);
        token = strtok(NULL, ",");
        logEntries[lineCount - 1].humidity = atoi(token);
        token = strtok(NULL, ",");
        logEntries[lineCount - 1].light = atoi(token);
        token = strtok(NULL, ",");
        strncpy(logEntries[lineCount - 1].time, token, sizeof(logEntries[lineCount - 1].time));

        lineCount++;
    }

    *numEntries = lineCount - 1;

    fclose(file);
}
void displayLogData(const struct LogEntry* logEntries, int numEntries) {
    printf("Log Entries:\n");
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].time);
    }
}
int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;
    extractLogData("data.csv", logEntries, &numEntries);
    displayLogData(logEntries, numEntries);
    return 0;
}