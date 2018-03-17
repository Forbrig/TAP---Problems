#include <stdio.h>

int n; //quantity of items (pizzas in this case)

int weight[20], value[20];

//position of the pointer or number of items, capacity of the backpack
int knapsack(int i, int capacity) {
  int result, a, b;
  if (i >= n) { //if has used all items
    return 0;
  } else if (weight[i] > capacity) { //if the current item is greater than the current capacity
    return (knapsack(i + 1, capacity));
  } else { //try the 2 available options, add the current item on the backpack or jump to the new
    a = knapsack(i + 1, capacity);
    b = value[i] + knapsack(i + 1, capacity - weight[i]);
    if (a > b) { //select the best
      result = a;
    } else {
      result = b;
    }
  }
  return result;
}



int main ( ) {
  /*
  n = number of orders
  p = max number of pizzas allowed that time
  */
  int i, p;

  scanf("%d", &n);

  while (n != 0) {
    scanf("%d", &p);
    for (i = 0; i < n; i++) {
      scanf("%d", &value[i]);
      scanf("%d", &weight[i]);
    }

    printf("%d min.\n", knapsack(0, p));
    scanf("%d", &n);
  }
  return 0;
}
