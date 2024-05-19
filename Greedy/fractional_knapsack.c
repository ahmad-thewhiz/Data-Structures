#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double profit;
    double weight;
    double value; // profit/weight
} Item;

// Comparison function to sort items based on their value in descending order
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->value > itemA->value) return 1;
    if (itemB->value < itemA->value) return -1;
    return 0;
}

double fractionalKnapsack(Item items[], int n, double W) {
    qsort(items, n, sizeof(Item), compare); 
    double totalProfit = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += items[i].value * W;
            break;
        }
    }
    return totalProfit;
}

int main() {
    int n;
    double W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &W);

    Item items[n];
    printf("Enter the profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Profit: ", i + 1);
        scanf("%lf", &items[i].profit);
        printf("Item %d - Weight: ", i + 1);
        scanf("%lf", &items[i].weight);
        items[i].value = items[i].profit / items[i].weight;
    }

    double maxProfit = fractionalKnapsack(items, n, W);
    printf("Maximum profit in the knapsack = %.2lf\n", maxProfit);

    return 0;
}
