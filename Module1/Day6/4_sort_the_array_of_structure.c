#include <stdio.h>
#include <stdlib.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void sortStudents(struct Student* students, int size) {
    int i, j;
    struct Student temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
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
    sortStudents(students, size);
    printf("\nStudent Details (Sorted by Marks in Descending Order):\n");
    displayStudents(students, size);
    free(students);
    return 0;
}