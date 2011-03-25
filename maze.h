#ifndef MAZE_H
#define MAZE_H

struct wall{

      //North = 0
      //South = 1
      //East = 2
      //West = 3

      bool walls[4];    
};

class Maze{
   private:   
    wall* maze;
    int rows;
    int columns;
    Gentree* mtree;
    bool buildhelp(int p, int c); // helper function for build
    //pass in a position, the position you want to compare, and it
    //returns true if successfully combined 2 trees
    
   public:
    Maze(int r, int c);
    ~Maze();
    void print(); // print the maze to the screen
    void build(int seed);
   
};


#endif // MAZE_H
