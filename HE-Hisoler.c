#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i=0; i<n; i++) scanf("%d", &arr[i]);
    
    int largest = arr[0];
    for(i=1; i<n; i++) if(arr[i] > largest) largest = arr[i];
    printf("The largest element in the array is: %d\n", largest);

    getchar();
    char str[200];
    int vowelCount = 0;
    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i=0; str[i]!='\0'; i++) {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
           str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U') {
            vowelCount++;
        }
    }
    printf("The number of vowels in the string is: %d\n", vowelCount);
    return 0;
}
