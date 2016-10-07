#include <iostream>
#include <sstream>
#include <list>
 
using namespace std;

void 
DFSvisit(list<int> *adj, int v, bool visited[])
{
  visited[v] = true;
 
  list<int>::iterator it;
  for (it = adj[v].begin(); it != adj[v].end(); ++it){
    if (visited[*it] == false){
      cout << v << " " << *it << endl;
      DFSvisit(adj, *it, visited);
    }
  }
}

void 
DFS(list<int> *adj, int v, int size)
{
  // Mark all the vertices as not visited
  bool *visited = new bool[size];
  for (int i = 1; i < size; i++)
    visited[i] = false;
 
  for (int i = 1; i < size; i++){
    if (visited[i] == false) {
      cout << i << " root" << endl;
      DFSvisit(adj, i, visited);
    }
  }
}

int 
main()
{
  int v;  

  string line;
  getline(cin, line);
  istringstream iss(line);
  iss >> v;

  list<int> *adj; 
  adj = new list<int>[v+1]; //start indexing at 1 instead of 0

  for (int i = 1; i < v+1; i++){
    getline(cin, line);
    istringstream iss(line);
    
    char c;
    int n;
    iss >> c >> c;  //ignore "x : 
    while (iss >> n) {
      adj[i].push_back(n);
    }
  }
  
  DFS(adj, 1, v+1);
 
  return 0;
}
