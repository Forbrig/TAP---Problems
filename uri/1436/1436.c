#include <stdio.h>

int main ( ) {
  int i, j, t[100];
  int m, n, k, aux;
  int bubble; //flag for bubble sort

  scanf("%d", &i); //number of entries
  for (m = 0; m < i; m++) {
    scanf ("%d", &j); //number of players
    for (n = 0; n < j; n++) {
      scanf("%d", &t[n]);
      //printf("%d\n", t[n]);

    }

    bubble = 1;
    while (bubble != 0) {
      bubble = 0;
      for (k = 0; k < j; k++) {
        if (t[k+1] < t[k] && k < (j-1)) {
          aux = t[k];
          t[k] = t[k+1];
          t[k+1] = aux;
          bubble++;
        }
      }
    }
    printf("Case %d: %d\n", m+1, t[(j/2)]);
  }

  return 0;
}
