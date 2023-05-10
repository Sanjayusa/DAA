#include <stdio.h>

void generateFactors(int n)
{
    printf("Factors of %d: ", n);

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    generateFactors(n);

    return 0;
}

