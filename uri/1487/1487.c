#include <stdio.h>

int n; //quantity of items

// this problem is not accepted with the normal knapsack 0-1
// we need to implement a interative form, saving the values already calculated

int cache[100][600]; // 100 number of elements x 600 minutes available (capacity)
int weight[100], value[100];


//position of the pointer or number of items, capacity of the backpack
int knapsack(int i, int capacity) {
  int result, a, b;
  if (i >= n || capacity == 0) { //if has used all items
    return 0;
  } else if (capacity < 0) {
    return -123456789;
  } else { //try the 2 available options, add the current item on the backpack or jump to the new
    if (cache[i][capacity] == -1) {
      a = value[i] + knapsack(i, capacity - weight[i]);
      cache[i][capacity] = a;
    } else {
      a = cache[i][capacity];
    }
    b = knapsack(i + 1, capacity);
    if (a > b) { //select the best
      result = a;
    } else {
      result = b;
    }
  }
  cache[i][capacity] = result;
  //printf("%d\n", result );
  return result;
}



int main ( ) {
  int i, k, l, t, j, res;
  j = 1;

  scanf("%d %d", &n, &t);
  while(n != 0 && t != 0) {
    for (k = 0; k < 100; k++) {
      for (l = 0; l < 600; l++) {
          cache[k][l] = -1;
      }
    }
    for (i = 0; i < n; i++) {
      scanf("%d %d", &weight[i], &value[i]);
    }
    res = knapsack(0, t);

    printf("Instancia %d\n", j);
    printf("%d\n\n", res);
    scanf("%d %d", &n, &t);

    /*
    for (k = 0; k < 10; k++) {
      for (l = 0; l < 80; l++) {
          printf("%d ", cache[k][l]);
      }
      printf("\n");
    }
    */

    j++;
  }
  return 0;
}
