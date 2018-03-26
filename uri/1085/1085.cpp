#include <bits/stdc++.h> //for map function
#include <map>
#include <algorithm>
#include <string>

using namespace std;

std::map<std::pair<string, string>, std::pair<char, int>> graph;
std::map<std::pair<string, string>, std::pair<char, int>>::iterator it;
// a matrix with the origin, the destination, the letter that it begins and the size of the word that means the distance


int insert (string origin, string goal, string s) {
  int size = s.size(); // distance between nodes
  graph[make_pair(origin, goal)] = make_pair(s[0], size); // <portugal, brasil> = <a, 5>; 'amigo'
  /*
  if (graph->first.find(origin) != graph.end()) {
    cout << "Origem existe" << '\n';
  } else {
    cout << "Origem não existe" << '\n';
    return -1;
  }
  */
  return 1;
}

int main ( ) {
  int m;
  string begin, end; // start and end of the path that we want
  string a, b, word;
  cin >> m;

  while (m != 0) {
    cin >> begin >> end;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> word;
      insert(a, b, word);
    }
    
    std::cout << '\n';
    for (it = graph.begin(); it != graph.end(); it++) {
      std::cout << it->first.first << " " << it->first.second << " " << it->second.first << " " << it->second.second << '\n';
    }

    graph.clear(); // excludes all pairs

    cin >> m;
  }


  return 0;
}
