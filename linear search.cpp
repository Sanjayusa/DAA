#include <stdio.h>

int linearSearch(int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return i; // Return the index of the target value
        }
    }

    return -1; // Target value not found
}

int main()
{
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int index = linearSearch(array, size, target);

    if (index != -1)
    {
        printf("Target value found at index %d.\n", index);
    }
    else
    {
        printf("Target value not found in the array.\n");
    }

    return 0;
}

