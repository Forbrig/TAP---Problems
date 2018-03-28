#include <cstdio>
#include <map> //for map function
#include <algorithm>
#include <string> //string manipulation
#include <queue> //for priority_queue
#include <vector>
#include <functional> //for greater comparator (because we wnat the minor value on priority_queue)
const int INF = 123456789;

using namespace std;

int m, n, g, k; //number of spells, number of halls (and their names), number of galleries, number of monsters
int spell_damage[1000], spell_mana[1000], monster[1000]; //dungeon = halls + galleries (an matrix graph)
array <array<int, 1000>, 1000> dungeon;

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

int dijkstra (int n) { // (size of the dungeon)
  typedef pair<int, pair<int, int>> E;
  E aux;
  priority_queue<E, vector<E>, greater<E> > pq; // what is the element that it will hold, how it will hold (vector), order criteria
  int u, alt, dist[n] = {INF}; // vector of distances

  for (int i = 1; i < n; i++) { // insert all distances on the priority_queue (initalizeds with INFINITE)
    pq.push(make_pair(INF, make_pair(i, -1))); // (distance, (current node, from where it comes))
  }

  pq.push(make_pair(0, make_pair(0, 0))); // add the source node
  dist[0] = 0; // holds the shorter path found till now

  while (!pq.empty()) {
    aux = pq.top();
    //printf("%d %d %d\n", aux.first, aux.second.first, aux.second.second);
    for (int v = 0; v < n; v++) { //iterate in the size of the matrix (n)
      u = aux.second.first; //node that we are looking
      if (dungeon[u][v] == 1) { //if there is an edge from u to v ("for each neighbor of u")
        alt = dist[u] + dungeon[u][u]; //dungeon[u][u] because the weight is in the vertex u not in the edge (u -> v)
        printf("alt %d distv %d\n", alt, dist[v]);
        if (alt < dist[v]) { //a shorter path to v has been found!
          printf("alt %d\n", alt);
          dist[v] = alt;
          pq.push(make_pair(dist[v], make_pair(v, u))); // dont matter if there is 2 weights for that vertex in the queue, it will always choose the smallest
        }
      }
    }

    pq.pop();
  }
  return dist[n-1];
}

/*
int dijkstra(int s, int g) { //(start node, goal) minor path returning the weight
  return weight; //smallest cost
}
*/

int main ( ) {
  int i, j, vertex1, vertex2;
  int monster_life;
  scanf("%d %d %d %d", &m, &n, &g, &k);

  while (m != 0 && n != 0 && g != 0 && k != 0 ) {
    /*
    for (i = 0; i < n; i++) { //reseting values of connections (edges)
      for (j = 0; j < n; j++) {
        dungeon[i][j] = 0;
      }
    }
    */
    dungeon = {0};

    //printf("Spells:\n");
    for (i = 0; i < m; i++) { //spells
      scanf("%d %d", &spell_mana[i], &spell_damage[i]);
      //printf("%d %d\n", spell_mana[i], spell_damage[i]);
    }
    //printf("\n");

    for (i = 0; i < g; i++) { //edges between vertexes
      scanf("%d %d", &vertex1, &vertex2);
      dungeon[vertex1-1][vertex2-1] = 1;
      dungeon[vertex2-1][vertex1-1] = 1;
    }

    //printf("Monsters\n");
    for (i = 0; i < k; i++) { //hall where the monster lives an his life
      scanf("%d %d", &j, &monster_life);
      j = j - 1; // because our halls names start from 0 and not from 1
      //printf("%d %d\n", j, monster_life);
      dungeon[j][j] = dungeon[j][j] + knapsack(0, monster_life); //already calculates the weight of that hall and saves where we have space [j][j]
      //printf("Mana: %d\n", dungeon[j][j]);
    }

    printf("%d\n", dijkstra(n));

    /*
    for (i = 0; i < n; i++) {
      printf("%d: ", i);
      for (j = 0; j < n; j++) {
        printf("%d ", dungeon[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    */

    scanf("%d %d %d %d", &m, &n, &g, &k);
  }
  return 0;
}
