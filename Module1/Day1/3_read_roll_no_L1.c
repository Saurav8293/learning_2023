#include <stdio.h>
float cal_percentage(float total_marks) {
    return (total_marks / 300) * 100;
}

void summary(int roll_no, char name[], float marks[]) {
    float total_marks = marks[0] + marks[1] + marks[2];
    float percentage = cal_percentage(total_marks);

    printf("Student Summary-->\n");
    printf("Roll No: %d\n", roll_no);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", marks[0]);
    printf("Math Marks: %.2f\n", marks[1]);
    printf("Chemistry Marks: %.2f\n", marks[2]);
    printf("Total Marks: %.2f\n", total_marks);
    printf("Percentage: %.2f\n", percentage);
}

void read_details() {
    int roll_no;
    char name[100];
    float marks[3];

    printf("Enter Roll No: ");
    scanf("%d", &roll_no);
    fflush(stdin);

    printf("Enter Name: ");
    fgets(name, sizeof(name), stdin);
    fflush(stdin);

    printf("Enter Physics Marks: ");
    scanf("%f", &marks[0]);

    printf("Enter Math Marks: ");
    scanf("%f", &marks[1]);

    printf("Enter Chemistry Marks: ");
    scanf("%f", &marks[2]);
    summary(roll_no, name, marks);
}

int main() {
    read_details();
    return 0;
}
