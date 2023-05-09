#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    int triangle[n][n]; // 2D array to store the triangle

    // fill the first column with 1s
    for (int i = 0; i < n; i++) {
        triangle[i][0] = 1;
    }

    // fill the rest of the triangle using the formula
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    // print the triangle
    printf("Pascal's triangle:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    return 0;
}

