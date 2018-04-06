#include <stdio.h>
#include <string.h>
#define MAX 1123

char G[MAX][MAX];
char GV[MAX][MAX]; //GRAFO VISITADO

void BFS(int i, int j) {
  GV[i][j] = 1; //visitado
  if (G[i-1][j] == '.' && GV[i-1][j] == 0) {
    BFS(i-1, j);
  }
  if (G[i+1][j] == '.' && GV[i+1][j] == 0) {
    BFS(i+1, j);
  }
  if (G[i][j-1] == '.' && GV[i][j-1] == 0) {
    BFS(i, j-1);
  }
  if (G[i][j+1] == '.' && GV[i][j+1] == 0) {
    BFS(i, j+1);
  }
  return;
}

int main ( ) {
  int N, M, clicks = 0;
  memset(GV, 0, sizeof(GV)); //zerando um array rapidamente
  scanf("%d %d\n", &N, &M); //lendo o /n do buffer
  //scaneia o grid
  for (int i = 0; i < N; i++) {
    fgets(G[i], MAX, stdin);
  }
/*
  for (int i = 0; i < N; i++) {
    printf("%s\n", G[i]);
  }
*/
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (G[i][j] == '.' && GV[i][j] == 0) {
        BFS(i, j);
        clicks++;
      }
    }
  }
  printf("%d\n", clicks);
  return 0;
}
