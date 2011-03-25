#include "tree2.h"

Gentree::Gentree(int sz) {     // Constructor
  size = sz;
  array = new int[sz];      // Create node array
  for(int i=0; i<sz; i++) array[i] = -1;
}

// Return TRUE if nodes are in different trees
bool Gentree::differ(int a, int b) {
  int root1 = FIND(a);   // Find root of node a
  int root2 = FIND(b);   // Find root of node b
  return root1 != root2;             // Compare roots
}

void Gentree::UNION(int a, int b) {  // Merge two subtrees
  int root1 = FIND(a);   // Find root of node a
  int root2 = FIND(b);   // Find root of node b
  if (root1 != root2) array[root2] = root1; // Merge
}

int Gentree::FIND(int curr) {  // Find root
  while (array[curr] != -1) 
  {
        curr = array[curr];
        count++;
  }
  return curr;  // At root
}
