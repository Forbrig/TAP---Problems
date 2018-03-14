#include <stdio.h>

int main ( ) {
  /*
  n = number of orders
  p = max number of pizzas allowed that time
  */
  int n, p, pizzas[20], minutes[20];
  int i, localsum, globalsum, pzamount;

  scanf("%d", &n);

  while (n != 0) {
    scanf("%d", &p);

    for (i = 0; i < n; i++) {
      scanf("%d", &minutes[i]);
      scanf("%d", &pizzas[i]);
      //printf("%d %d\n", minutes[i], pizzas[i]);
    }

    pzamount = localsum = globalsum = 0;
    for (i = 0; i < n; i++) {
      if (pzamount + pizzas[i] <= n) {
        if (pizzas[i] / minutes[i] > globalsum) {
          globalsum = minutes[i];
          pzamount = pizzas[i];
        }
      }
    }

    scanf("%d", &n);
  }

  return 0;
}
