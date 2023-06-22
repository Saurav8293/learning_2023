#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void parseInputString(const char* input, struct Student* students, int size) {
    char temp[50];
    int i = 0;
    const char delimiter[2] = " ";
    char* token;
    strcpy(temp, input);
    token = strtok(temp, delimiter);
    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, delimiter);
        strcpy(students[i].name, token);
        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);
        token = strtok(NULL, delimiter);
        i++;
    }
}
int main() {
    int size, i;
    char input[100];
    struct Student* students;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();
    students = (struct Student*)malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    printf("\nEnter the input string in the format 'rollno name marks' for %d students:\n", size);
    for (i = 0; i < size; i++) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 
        parseInputString(input, &students[i], size);
    }
    printf("\nStudent Details:\n");
    for (i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
    free(students);
    return 0;
}
