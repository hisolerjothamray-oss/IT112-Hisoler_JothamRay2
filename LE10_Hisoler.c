#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp;
    char note[200];
    int n, i;

    fp = fopen("notes.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Writing Notes File:\n");
    printf("How many notes do you want to record? ");
    scanf("%d", &n);
    getchar();  /* clear leftover newline */

    for (i = 1; i <= n; i++) {
        printf("Note %d: ", i);
        fgets(note, sizeof(note), stdin);
        note[strcspn(note, "\n")] = '\0';   /* remove newline */
        fprintf(fp, "%s\n", note);
    }
    fclose(fp);
    printf("\nInitial notes saved successfully.\n");

    fp = fopen("notes.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nEnter one additional note:\n");
    fgets(note, sizeof(note), stdin);
    note[strcspn(note, "\n")] = '\0';
    fprintf(fp, "%s\n", note);
    fclose(fp);
    printf("\nNew note added successfully.\n");

    fp = fopen("notes.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nReading Saved Notes:\n\n");
    i = 1;
    while (fgets(note, sizeof(note), fp) != NULL) {
        note[strcspn(note, "\n")] = '\0';
        printf("%d. %s\n", i++, note);
    }
    fclose(fp);

    return 0;
}
