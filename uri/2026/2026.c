#include <stdio.h>

/*
This problem is a classical knapsack (0-1) case.
here we need to put biggest number of decorations in a branch of the christmas tree respecting the weght that it supports,
each branch have a capacity so we need to choose the combination
of packages (weights) that have the biggest number of decorations (value) and fits in the branch capacity.
*/


int weight[100], value[100];

int knapsack(int i, int n, int capacity) { //(current item, number of elements, current capacity)
  int a, b, result;
  if (i >= n) {
    return 0;
  } else if (weight[i] > capacity) { //if the current capacity dont support the current weight
    return knapsack(i + 1, n, capacity);
  } else {
    a = knapsack(i + 1, n, capacity); //dont use the current item
    b = value[i] + knapsack(i + 1, n, capacity - weight[i]); //use the current item
    if (a > b) {
      result = a;
    } else {
      result = b;
    }
  }
  return result;
}

int main ( ) {
  int i, j, n, m, capacity, res;
  scanf("%d", &n); //number of tests
  for (i = 0; i < n; i++) {
    scanf("%d", &m); //number of packages
    scanf("%d", &capacity); //capacity of the branch
    for (j = 0; j < m; j++) {
      scanf("%d %d", &value[j], &weight[j]);
    }
    res = knapsack(0, m, capacity);
    printf("Galho %d:\n", i + 1);
    printf("Numero total de enfeites: %d\n\n", res);

  }
  return 0;
}
