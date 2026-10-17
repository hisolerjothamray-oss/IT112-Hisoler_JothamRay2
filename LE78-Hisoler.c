
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, i;
    int largest;
    int vowels = 0;
    int isVowel;
    int arr[100];
    char str[500];

    // Part 1: Find the Largest Element in an Array
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("The largest element in the array is: %d\n",
           largest);

    // Part 2: Count the Number of Vowels in a String
    getchar(); // Consume the leftover newline

    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower((unsigned char)str[i]);
        isVowel = (ch == 'a' || ch == 'e' ||
                   ch == 'i' || ch == 'o' ||
                   ch == 'u');

        if (isVowel) {
            vowels++;
        }
    }

    printf("The number of vowels in the string is: %d\n",
           vowels);

    return 0;
}
