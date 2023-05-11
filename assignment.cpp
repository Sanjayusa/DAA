#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int n;
int cost[MAX][MAX];
bool assigned[MAX];
int assignment[MAX];

int calculateCost(int agent, int task) {
    int totalCost = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (assignment[i] != -1) {
            totalCost += cost[i][assignment[i]];
        }
    }
    return totalCost + cost[agent][task];
}

void branchAndBound(int agent, int totalCost, int assignedTasks) {
    int i;
    for (i = 0; i < n; i++) {
        if (!assigned[i]) {
            assigned[i] = true;
            assignment[agent] = i;
            int newTotalCost = calculateCost(agent, i);
            if (assignedTasks == n - 1) {
                if (newTotalCost < totalCost) {
                    totalCost = newTotalCost;
                }
            } else {
                branchAndBound(agent + 1, totalCost, assignedTasks + 1);
            }
            assigned[i] = false;
            assignment[agent] = -1;
        }
    }
}

void input() {
    printf("Enter the number of agents and tasks (n): ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
}

void initialize() {
    int i;
    for (i = 0; i < n; i++) {
        assigned[i] = false;
        assignment[i] = -1;
    }
}

void printAssignment() {
    int i;
    printf("Optimal Assignment:\n");
    for (i = 0; i < n; i++) {
        printf("Agent %d -> Task %d\n", i + 1, assignment[i] + 1);
    }
}

int main() {
    input();
    initialize();
    branchAndBound(0, 0, 0);
    printAssignment();
    return 0;
}

