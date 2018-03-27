#include <bits/stdc++.h>
#include <map> //for map function
#include <algorithm>
#include <string> //string manipulation
#include <queue> //for priority_queue
#include <functional> //for greater comparator (because we wnat the minor value on priority_queue)
#define INF 123456789

using namespace std;

// a matrix with the origin, the destination, the letter that the word begins and the distance (size of the word)
map<pair<string, string>, pair<char, int>> graph;
map<pair<string, string>, pair<char, int>> :: iterator it;
vector<pair<int, string>> dist;
vector<pair<int, string>> :: iterator it_dist; // holds the distance from source till the node and from where it comes (for dijkstra)
//vector<string> prior; // holds from where the path comes to get that distance on dist (the prior node)

// distances from the goal till this arbitrary vertex
void insert_dist(int distan, string vertex, string prior) { //insert (or update) distance and from what node it comes
  for (unsigned int i = 0; i < dist.size(); i++) { //search for the vertex name
    if (dist[i].second == vertex) {
      //dist[i].third = prior;
      dist[i].first = distan;
      return;
    }
  }
  // if it reached here it means it dont exist, make new pair
  dist.push_back(make_pair(distan, vertex));
  //dist = make_pair(distan, vertex);
  return;
}

void insert (string origin, string goal, string s) {
  int size = s.size(); // distance between nodes
  graph[make_pair(origin, goal)] = make_pair(s[0], size); // <portugal, brasil> = <a, 5>; 'amigo'
  insert_dist(INF, origin, origin);
  insert_dist(INF, goal, goal);

  return;
}

// dijkstra adapted for this problem data representation and restriction
void dijkstra(string source) {
  insert_dist(0, source, source);
  // the variable, what kind of queue, a comparator to order by the smallest element (order criteria, the default is the biggest element first)
  priority_queue<int, vector<pair<int, string>>, std::greater<pair<int, string>>> pq;
  for (unsigned int i = 0; i < dist.size(); i++) { // insert all distances on the priority_queue (initalizeds with INFINITE)
    pq.push(dist[i]);
  }


  while (!pq.empty()) {
    pair<int, string> aux = pq.top();
    pq.pop(); // withdraw the minor value


  }
  /*
  // print the priority_queue
  while (!pq.empty()) {
    pair<int, string> aux = pq.top();
    pq.pop();
    cout << aux.first << " " << aux.second << "\n";
  }
  */

  return;
}

int main ( ) {
  int m;
  string begin, end; // start and end of the path that we want
  string a, b, word;
  cin >> m;

  while (m != 0) {
    cin >> begin >> end;
    insert_dist(INF, begin, begin); //infinite distance
    insert_dist(INF, end, end);
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> word;
      insert(a, b, word);
      insert(b, a, word);
    }
    dijkstra(begin);


    /*
    std::cout << '\n';
    for (it_dist = dist.begin(); it_dist != dist.end(); it_dist++) {
      std::cout << it_dist->first << " " << it_dist->second << '\n';
    }
    */
    /*
    std::cout << '\n';
    for (it = graph.begin(); it != graph.end(); it++) {
      std::cout << it->first.first << " " << it->first.second << " " << it->second.first << " " << it->second.second << '\n';
    }
    */

    dist.clear(); // clear the distances
    graph.clear(); // excludes all pairs

    cin >> m;
  }
  return 0;
}
