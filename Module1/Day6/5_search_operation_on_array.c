#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void searchStudentByName(struct Student* students, int size, const char* name) {
    int i;
    int found = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found!\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}
int main() {
    int size, i;
    struct Student* students;
    char searchName[20];
    printf("Enter the number of students: ");
    scanf("%d", &size);
    students = (struct Student*)malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    printf("Enter student details:\n");
    for (i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter the roll number: ");
        scanf("%d", &(students[i].rollno));
        printf("Enter the name: ");
        scanf("%s", students[i].name);
        printf("Enter the marks: ");
        scanf("%f", &(students[i].marks));
    }
    printf("\nEnter the name of the student to search: ");
    scanf("%s", searchName);
    searchStudentByName(students, size, searchName);
    free(students);
    return 0;
}