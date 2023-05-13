#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 4   // Number of items
#define W 7   // Knapsack capacity

int values[N] = {10, 20, 30, 40};  // Item values
int weights[N] = {2, 3, 4, 5};     // Item weights

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

int max(int a, int b) {
    return a > b ? a : b;
}

double bound(struct Node u) {
    if (u.weight >= W) {
        return 0;
    }
    double bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((j < N) && (totweight + weights[j] <= W)) {
        totweight += weights[j];
        bound += values[j];
        j++;
    }
    if (j < N) {
        bound += (W - totweight) * ((double)values[j] / weights[j]);
    }
    return bound;
}

void knapsack() {
    struct Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u);
    int maxProfit = 0;
    int queueSize = 1;
    struct Node queue[100];
    queue[0] = u;
    while (queueSize > 0) {
        u = queue[queueSize - 1];
        queueSize--;
        if (u.bound > maxProfit) {
            v.level = u.level + 1;
            v.weight = u.weight + weights[v.level];
            v.profit = u.profit + values[v.level];
            if (v.weight <= W && v.profit > maxProfit) {
                maxProfit = v.profit;
            }
            v.bound = bound(v);
            if (v.bound > maxProfit) {
                queue[queueSize] = v;
                queueSize++;
            }
            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = bound(v);
            if (v.bound > maxProfit) {
                queue[queueSize] = v;
                queueSize++;
            }
        }
    }
    printf("Maximum profit: %d\n", maxProfit);
}

int main() {
    knapsack();
    return 0;
}

