#ifndef TREE_H
#define TREE_H

class Gentree {                // Gentree for UNION/FIND
private:
  int* array;                  // Node array
  int size;                    // Size of node array
  int FIND(int);         // Find root
  
public:
  int count;                   // number of times FIND is run
  Gentree(int);                // Constructor
  ~Gentree() { delete [] array; } // Destructor
  void UNION(int, int);        // Merge equivalences
  bool differ(int, int);       // TRUE if not in same tree
};
#endif // TREE_H
