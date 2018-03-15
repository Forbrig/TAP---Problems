#include <stdio.h>

int main ( ) {
  /*
  n = number of orders
  p = max number of pizzas allowed that time
  */
  int n, p, pizzas[20], minutes[20], media[20], usable[20];
  int i, localsum, globalsum, pzamount;
  int aux, aux2, aux3, k, bubble;

  scanf("%d", &n);

  while (n != 0) {
    scanf("%d", &p);
    for (i = 0; i < n; i++) {
      scanf("%d", &minutes[i]);
      scanf("%d", &pizzas[i]);
      usable[i] = 1;
      media[i] = (minutes[i] / pizzas[i]); //average of minute / pizza
    }

    // sort by the average of minute / pizza
    bubble = 1;
    while (bubble != 0) {
      bubble = 0;
      for (k = 0; k < i; k++) {
        if (media[k+1] < media[k] && k < (i-1)) {
          aux = media[k];
          aux2 = minutes[k];
          aux3 = pizzas[k];

          media[k] = media[k+1];
          minutes[k] = minutes[k+1];
          pizzas[k] = pizzas[k+1];

          media[k+1] = aux;
          minutes[k+1] = aux2;
          pizzas[k+1] = aux3;

          bubble++;
        }
      }
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
