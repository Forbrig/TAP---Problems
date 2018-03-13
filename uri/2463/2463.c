#include <stdio.h>

int main ( ) {
  int i, j, vida, soma, sala[50000];

  scanf("%d", &i);

  for (j = 0; j < i; j++) {
    scanf("%d", &sala[j]);
  }


  // complexity O(n)
  for (j = 0; j < i; j++) {
    if (j == 0) {
      vida = sala[j];
      soma = sala[j];
    } else {

      if (soma + sala[j] < sala[j]) {
        /*
        if the sum is less than the next number it don't make sense to keep the old sum,
        instead we start suming from the big value
        */
        soma = sala[j];
      } else {
        /*
        could be that the sum of distant numbers is worth so we need to keep suming
        in case this happen. ex: 8 -5 8
        */ 
        soma = soma + sala[j];
      }

      if (soma > vida) {
        vida = soma;
      }
    }
  }

  printf("%d\n", vida);

  return 0;
}
