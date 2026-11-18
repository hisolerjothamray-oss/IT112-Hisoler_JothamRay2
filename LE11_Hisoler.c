
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    int idNumber;
    char name[100], section[50];
    int choice;

    do {
        fp = fopen("student_records.txt", "a");

        if (fp == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        printf("Enter Student Number: ");
        scanf("%d", &idNumber);
        getchar();

        printf("Enter Complete Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter Section: ");
        fgets(section, sizeof(section), stdin);
        section[strcspn(section, "\n")] = '\0';

        fprintf(fp, "ID Number: %d\n", idNumber);
        fprintf(fp, "Complete Name: %s\n", name);
        fprintf(fp, "Section: %s\n\n", section);

        fclose(fp);

        printf("\nRecord added and saved successfully.\n\n");

        printf("Add another student? [Enter 1 for Yes, 0 for No]: ");
        scanf("%d", &choice);

        printf("\n");

    } while (choice == 1);

    printf("All student records have been saved.\n");

    return 0;
}
