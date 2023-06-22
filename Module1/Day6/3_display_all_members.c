#include <stdio.h>
#include <stdlib.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void displayStudents(struct Student* students, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}
int main() {
    int size, i;
    struct Student* students;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    students = (struct Student*)malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    displayStudents(students, size);
    free(students);
    return 0;
}