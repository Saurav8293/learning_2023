#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 4096
void changeCase(char* buffer, char option) {
    int i;
    switch (option) {
        case 'u':
            for (i = 0; buffer[i] != '\0'; i++) {
                buffer[i] = toupper(buffer[i]);
            }
            break;
        case 'l':
            for (i = 0; buffer[i] != '\0'; i++) {
                buffer[i] = tolower(buffer[i]);
            }
            break;
        case 's':
            for (i = 0; buffer[i] != '\0'; i++) {
                if (islower(buffer[i])) {
                    buffer[i] = toupper(buffer[i]);
                }
            }
            break;
        default:
            break;
    }
}
int main(int argc, char* argv[]) {
    FILE* sourceFile;
    FILE* targetFile;
    char sourcePath[100];
    char targetPath[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    char option = '\0';
    if (argc < 3) {
        printf("Insufficient arguments. Usage: ./cp <option> <source-file> <target-file>\n");
        return 1;
    }
    option = argv[1][1];
    strcpy(sourcePath, argv[2]);
    strcpy(targetPath, argv[3]);
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open source file. Exiting...\n");
        return 1;
    }
    targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create target file. Exiting...\n");
        fclose(sourceFile);
        return 1;
    }
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        changeCase(buffer, option);
        fwrite(buffer, 1, bytesRead, targetFile);
    }
    printf("File copied successfully.\n");
    fclose(sourceFile);
    fclose(targetFile);
    return 0;
}