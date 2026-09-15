#include <stdio.h>

int main() {
    int num;
    int sum = 0;

    printf("Enter positive numbers to ADD (zero or negative number to STOP)\n");

    do {
        printf("\nEnter a number: ");
        scanf("%d", &num);

        if (num > 0) {
            sum += num;
        }


    } while (num > 0);

    printf("Total sum is: %d\n", sum);

    return 0;
}
