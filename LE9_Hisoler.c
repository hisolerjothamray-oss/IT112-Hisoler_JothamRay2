#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file;
    int numberOfStudents;
    int age;
    char name[100];
    char course[100];
    char line[256];
    char input[50];

    /* Open the file in write mode */
    file = fopen("student_records.txt", "w");

    if (file == NULL) {
        printf("Error: Could not create the file.\n");
        return 1;
    }

    printf("Writing Student Database:\n");
    printf("How many students do you want to record? ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Invalid input.\n");
        fclose(file);
        return 1;
    }

    numberOfStudents = atoi(input);

    if (numberOfStudents <= 0) {
        printf("Please enter a valid number of students.\n");
        fclose(file);
        return 1;
    }

    for (int i = 1; i <= numberOfStudents; i++) {
        printf("\nStudent %d\n", i);

        printf("Enter Name: ");
        if (fgets(name, sizeof(name), stdin) == NULL) {
            printf("Error reading name.\n");
            fclose(file);
            return 1;
        }
        name[strcspn(name, "\n")] = '\0';

        printf("Enter Age: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading age.\n");
            fclose(file);
            return 1;
        }
        age = atoi(input);

        printf("Enter Course: ");
        if (fgets(course, sizeof(course), stdin) == NULL) {
            printf("Error reading course.\n");
            fclose(file);
            return 1;
        }
        course[strcspn(course, "\n")] = '\0';

        fprintf(file, "Student %d\n", i);
        fprintf(file, "Name: %s\n", name);
        fprintf(file, "Age: %d\n", age);
        fprintf(file, "Course: %s\n", course);
        fprintf(file, "------------------------\n");
    }

    fclose(file);
    printf("\nStudent database successfully saved to file.\n");

    /* Reopen the file in read mode */
    file = fopen("student_records.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open the file for reading.\n");
        return 1;
    }

    printf("\nReading Student Database:\n\n");

    /* Read and display the file line by line */
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
