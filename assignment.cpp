#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

void printAssignment(int assignment[MAX_SIZE], int size)
{
    printf("Optimal Assignments:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Person %d -> Task %d\n", i + 1, assignment[i] + 1);
    }
}

bool isSafe(int person, int task, int assignment[MAX_SIZE], int size, int costMatrix[MAX_SIZE][MAX_SIZE], bool assigned[MAX_SIZE])
{
    // Check if the task is already assigned to someone else
    if (assigned[task])
    {
        return false;
    }

    // Check if the cost of assigning the task to the person is less than the current assignment
    if (costMatrix[person][task] >= assignment[person])
    {
        return false;
    }

    return true;
}

void branchAndBoundUtil(int person, int assignment[MAX_SIZE], int size, int costMatrix[MAX_SIZE][MAX_SIZE], int currentCost, int *minCost, bool assigned[MAX_SIZE])
{
    if (person == size)
    {
        if (currentCost < *minCost)
        {
            *minCost = currentCost;
            return;
        }
    }

    for (int task = 0; task < size; task++)
    {
        if (isSafe(person, task, assignment, size, costMatrix, assigned))
        {
            // Assign the task to the person
            assigned[task] = true;
            assignment[person] = task;
            int newCost = currentCost + costMatrix[person][task];

            branchAndBoundUtil(person + 1, assignment, size, costMatrix, newCost, minCost, assigned);

            // Undo the assignment
            assigned[task] = false;
            assignment[person] = -1;
        }
    }
}

void branchAndBound(int costMatrix[MAX_SIZE][MAX_SIZE], int size)
{
    int assignment[MAX_SIZE];
    bool assigned[MAX_SIZE] = {false};
    int minCost = __INT_MAX__;

    branchAndBoundUtil(0, assignment, size, costMatrix, 0, &minCost, assigned);

    if (minCost == __INT_MAX__)
    {
        printf("No feasible solution found.\n");
    }
    else
    {
        printAssignment(assignment, size);
        printf("Minimum Cost: %d\n", minCost);
    }
}

int main()
{
    int costMatrix[MAX_SIZE][MAX_SIZE];
    int size;

    printf("Enter the size of the matrix (square matrix): ");
    scanf("%d", &size);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    branchAndBound(costMatrix, size);

    return 0;
}

