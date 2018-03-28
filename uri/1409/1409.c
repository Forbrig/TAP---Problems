#include <stdio.h>

int m, n, g, k; //number of spells, number of halls (and their names), number of galleries, number of monsters
int spell_damage[1000], spell_mana[1000], dungeon[1000][1000], monster[1000]; //dungeon = halls + galleries (an matrix graph)
const int INF = 123456789;


//knapsack_unbounded = can use the same item over and over
int knapsack(int i, int capacity) { //(position of item in the vector, capacity of knapsack)
  int a, b;

  if (i >= m) { //looked at all spells (discad this branch)
    return INF;
    //we want the smallest value of mana that can kill the mob,
    //so this is how we discard this option: put infinite in the branch that has used a combination of spells that dont killed
    //the monster.
    //printf("has used all the spells\n");
  } else if (capacity <= 0) { // capacity < spell_damage[i] can happen!
    return 0;
    //printf("killed\n");
    //we have killed the monster!
    //that means this branch as a combination of spells that cost some mana but can kill the monster,
    //and we can stop expanding this branch and return this combination.
  } else {
    a = spell_mana[i] + knapsack(i, capacity - spell_damage[i]); //reuse the current spell
    b = knapsack(i + 1, capacity); //try the next spell
    if (a < b) { //return the smallest ammount of mana that can kill the monster (something like minmax: minimal ammount of the max that we can use)
      return a;
    }
    return b;
  }
}


int main ( ) {
  int i, j, vertex1, vertex2;
  int monster_life;
  scanf("%d %d %d %d", &m, &n, &g, &k);

  while (m != 0 && n != 0 && g != 0 && k != 0 ) {
    for (i = 0; i < n; i++) { //reseting values of connections (edges)
      for (j = 0; j < n; j++) {
        dungeon[i][j] = 0;
      }
    }

    printf("Spells:\n");
    for (i = 0; i < m; i++) { //spells
      scanf("%d %d", &spell_mana[i], &spell_damage[i]);
      printf("%d %d\n", spell_mana[i], spell_damage[i]);
    }
    printf("\n");

    for (i = 0; i < g; i++) { //edges between vertexes
      scanf("%d %d", &vertex1, &vertex2);
      dungeon[vertex1-1][vertex2-1] = 1;
      dungeon[vertex2-1][vertex1-1] = 1;
    }

    printf("Monsters\n");
    for (i = 0; i < k; i++) { //hall where the monster lives an his life
      scanf("%d %d", &j, &monster_life);
      j = j - 1; // because our halls names start from 0 and not from 1
      printf("%d %d\n", j, monster_life);
      dungeon[j][j] = dungeon[j][j] + knapsack(0, monster_life); //already calculates the weight of that hall and saves where we have space [j][j]
      printf("Mana: %d\n", dungeon[j][j]);
    }


    for (i = 0; i < n; i++) {
      printf("%d: ", i);
      for (j = 0; j < n; j++) {
        printf("%d ", dungeon[i][j]);
      }
      printf("\n");
    }
    printf("\n");


    scanf("%d %d %d %d", &m, &n, &g, &k);
  }
  return 0;
}
