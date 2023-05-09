#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("  "); // print spaces for formatting
        }
        for (int j = 1; j <=i; j++) {
            printf(" %d ", j); // print numbers
        }
        printf("\n"); // move to next line after each row
    }

    return 0;
}
