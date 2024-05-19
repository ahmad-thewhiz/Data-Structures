#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int profit;
    int deadline;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int *slots = (int *)calloc(maxDeadline, sizeof(int));

    char *result = (char *)malloc(maxDeadline * sizeof(char));

    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = 0;
        result[i] = '\0';
    }

    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                slots[j] = 1;      
                result[j] = jobs[i].id; 
                totalProfit += jobs[i].profit; 
                break;
            }
        }
    }

    printf("Job sequence for maximum profit: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != '\0') {
            printf("%c ", result[i]);
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);

    free(slots);
    free(result);
}

int main() {
    Job jobs[] = { {'a', 100, 2}, {'b', 19, 1}, {'c', 27, 2}, {'d', 25, 1}, {'e', 15, 3} };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
