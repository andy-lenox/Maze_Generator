// Name:         Andrew Lenox
// Program:      CSC 375 Program 4
// Due Date:     04/06/09
// Compiler:     Bloodshed Dev C++

#include <iostream>
#include <cstdlib>
using namespace std;


#include "tree.cpp"
#include "maze.cpp"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
       cout << "Usage: prog04.ext (seed) (rows) (colums)";
       exit(1);
    }
    int seed = atoi(argv[1]); //random seed of the maze
    int rows = atoi(argv[2]); //number of rows in the maze
    int cols = atoi(argv[3]); // number of columns in the maze
    Maze maze = Maze(rows,cols); // initialize the maze
    maze.build(seed); // build the maze
    maze.print();   // print the maze
}
 
