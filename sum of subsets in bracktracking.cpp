#include <stdio.h>

#define MAX_SIZE 100

void findSubsets(int arr[], int n, int sum, int currSum, int currIndex, int subset[], int subsetSize);

void sumOfSubsets(int arr[], int n, int sum)
{
    int subset[MAX_SIZE];
    findSubsets(arr, n, sum, 0, 0, subset, 0);
}

void findSubsets(int arr[], int n, int sum, int currSum, int currIndex, int subset[], int subsetSize)
{
    if (currSum == sum)
    {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (currIndex == n || currSum > sum)
    {
        return;
    }

    // Include the current element in the subset
    subset[subsetSize] = arr[currIndex];
    findSubsets(arr, n, sum, currSum + arr[currIndex], currIndex + 1, subset, subsetSize + 1);

    // Exclude the current element from the subset
    findSubsets(arr, n, sum, currSum, currIndex + 1, subset, subsetSize);
}

int main()
{
    int arr[100],sum,n,i;
    printf("enter the no of array :");
    scanf("%d",&n);
    printf("enter the array :");
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
	}
	printf("enter the sum value :");
    scanf("%d",&sum);
    printf("Subsets with sum %d:\n", sum);
    sumOfSubsets(arr, n, sum);

    return 0;
}

