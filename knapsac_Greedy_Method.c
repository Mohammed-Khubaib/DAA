#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratioI = (double)items[i].value / items[i].weight;
            double ratioJ = (double)items[j].value / items[j].weight;
            if (ratioI < ratioJ) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }

        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (remainingCapacity / (double)items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 15;
    // struct Item items[] = {{10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}};
    struct Item items[] = {{5, 1}, {10,3}, {15, 5},{7,4} ,{8,1},{9,3},{4,2}};

    
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(capacity, items, n);

    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}