#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

void computeContainerLoading(int containers[MAX_CONTAINERS], int numContainers, int items[MAX_ITEMS], int numItems)
{
    int containerIndex = 0;
    int currentItem = 0;

    while (currentItem < numItems)
    {
        if (containers[containerIndex] >= items[currentItem])
        {
            containers[containerIndex] -= items[currentItem];
            currentItem++;
        }
        else
        {
            containerIndex++;
            if (containerIndex == numContainers)
            {
                printf("Not all items can be loaded into the containers.\n");
                return;
            }
        }
    }

    printf("All items are successfully loaded into the containers.\n");
}

int main()
{
    int containers[MAX_CONTAINERS];
    int items[MAX_ITEMS];
    int numContainers, numItems;

    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    printf("Enter the dimensions of the containers:\n");
    for (int i = 0; i < numContainers; i++)
    {
        scanf("%d", &containers[i]);
    }

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the dimensions of the items:\n");
    for (int i = 0; i < numItems; i++)
    {
        scanf("%d", &items[i]);
    }

    computeContainerLoading(containers, numContainers, items, numItems);

    return 0;
}

