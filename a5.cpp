#include <iostream>
#include <vector>

using namespace std;

/*
  Construct P0, initial predecessor matrix
*/
int** 
initializePredecessors(int **D, int v) 
{
  int **P;
  P = new int *[v+1];

  // Initialize all values to NIL
  for (int i = 0; i < v+1; i++) {
    P[i] = new int[v+1];
    for (int j = 0; j < v+1; j++) {
      P[i][j] = -1;
    }
  }

  // Initialize all predecessors
  for (int i = 1; i <= v; i++) {
    for (int j = 1; j <= v; j++) {
      if (D[i][j] != 0 && D[i][j] != 101) {
	P[i][j] = i;
      }
    }
  }
  return P;
}


/*
  Floyd-Warshall algorithm using predecessor matrix
*/
int** 
floydWarshall(int **D, int v) 
{
  int **P = initializePredecessors(D, v);

  for (int k = 1; k <= v; k++) {
    for (int i = 1; i <= v; i++) {
      for (int j = 1; j <= v; j++) {
	
	// Skip if edge doesn't exist
	if (D[i][k] == 101 || D[k][j] == 101) {
	  continue;                  
	}
        
	/* If the weight of the path including node k is less than the
	   path without k, then we include k in path and also update 
	   the predecessor */
	if (D[i][j] > D[i][k] + D[k][j]) {
	  D[i][j] = D[i][k] + D[k][j];
	  P[i][j] = P[k][j];
	}
      }
    }
  }
  return P;
}
/*
  Prints out the shortest path from node i to j.
  getPath() recurses from node j to i (backwards), 
  printing out the nodes along the way. Since we check
  if a path exists before calling getPath(), getPath()
  will always print out a valid path from i to j.
*/
void
getPath(int **P, int i, int j)
{
  // Reached the first node, print it out
  if (i == j) {
    cout << i << endl;
  // Recurse on the predecessor of j
  } else {
    getPath(P, i, P[i][j]);
    cout << j << endl;
  } 
}



int 
main()
{
  // Get number of nodes and edges
  int v, e;  
  cin >> v >> e;
  
  // 2D array for the weight matrix
  int **D;
  D = new int *[v+1];

  // Initialize all weights to 101
  // We will use 101 as infinity
  for (int a = 0; a < v+1; a++){
    D[a] = new int[v+1];
    for (int b = 0; b < v+1; b++){
      D[a][b] = 101; 
    }
  }

  // If i == j, set Dij to 0
  for (int a = 0; a < v+1; a++){
      D[a][a] = 0; 
  }

  // Update weight matrix from user input
  for (int k = 0; k < e; k++){
    int i, j, w;
    cin >> i >> j >> w;
    D[i][j] = w; 
  }

  // Path will be from node i to j
  int i, j;
  cin >> i >> j;
  
  // Create the predecessor matrix
  int **P = floydWarshall(D, v);

  // If D[i][j] equals infinity, then there is no path from i to j
  if (D[i][j] == 101) {
    cout << -1 << endl;
  } else {
    getPath(P, i, j);
    cout << D[i][j] << endl;
  }

  return 0;
}
