#include "maze.h"

Maze::Maze(int r, int c)
{
   rows = r;  //store rows
   columns = c;  //store columns
   int size = rows*columns; //the size of the array
   maze = new wall[size];  //create the array of walls
   mtree = new Gentree(size); //create the tree
   
   //initialize all walls to true
   for ( int i = 0; i < size ; i++)
       for ( int j = 0; j < 4; j++)
           maze[i].walls[j] = true;
   
   maze[0].walls[0] = false; //set the entrance
   maze[size-1].walls[1] = false; //set the exit
}


Maze::~Maze(){
              
   delete [] maze;
   maze = NULL;
   delete mtree;
   mtree = NULL;         
}

void Maze::print(){

     for (int r = 0 ; r < rows ; r++)//iteration through every row
     {
         for (int c = 0 ; c < columns ; c++) // iteration for north wall
         {
             cout << "+";
             int position = (r*columns) + c;
             if (maze[ position ].walls[0]==true) //if the north wall of the rth row in the cth column is present
                cout << "-";                    //print a wall
             else                               //else print a space
                cout << " ";                    
         }
         cout << "+" << endl;
         for (int c = 0 ; c < columns ; c++) // iteration for west wall
         {
             int position = (r*columns) + c;
             if (maze[ position ].walls[3]==true) //if the west wall of the rth row in the cth column is present
                cout << "| ";                   //print a wall, and a space
             else                               //else print 2 spaces
                cout << "  ";
         }
         cout << "|";
         cout << endl;
     }
     
     cout << "+"; //begin the last row
     for (int c = 0 ; c < (columns-1) ; c++) // iteration for southmost wall
     {
         cout << "-+";
     }
     cout << " +"; //the end of the last row
     
     cout << endl << "Count: " << mtree->count;
          
}

void Maze::build(int seed){
     
     int size = (rows * columns); //size of the maze
     int numoftrees = size;       //keep track of the number of trees left
     srand(seed);                 //seed the random numbers
     int position;                //current position
     int direction;               //N,S,E or W (0,1,2,3 respectively)
     int compare;                 //the position we want to compare with current

     
     while ( numoftrees > 1 )
     {
           //get a random position in the maze, and a random direction
           //directions 0,1,2,3 - N,S,E,W respectively
           position = 0+(int) (((float) (size-1)) *rand()/(RAND_MAX+1.0));
           direction = 0+(int) (((float) (4)) *rand()/(RAND_MAX+1.0));
           
           //if North
           if ( direction == 0 ){
              
              
              if( position < columns ){
                  // if the direction is north and we are in the first row
                  // do nothing
              }
              //if we are able to perform a UNION on the 2 positions
              else 
              {
                   //the compare position is one row back
                   compare = position - columns;
                   if (buildhelp(position, compare)) {
                      //break down the north wall of the current pos
                      maze[position].walls[0] = false;
                      //break down the south wall of the compare pos
                      maze[compare].walls[1] = false;
                      //reduce the number of trees by one
                      numoftrees--;
                      }     
              }
           }
           else if ( direction == 1 ){
             //bounds checking 
             if ( (position + columns) < size )
             { 
                if((position < size) && (position > (size - (columns-1)))){
                //if the direction is south and we are in the last row
                //try again
                }
                else
                {
                     compare = position + columns;
                     if ( buildhelp(position, compare) ){
                        maze[position].walls[1] = false;
                        maze[compare].walls[0] = false;
                        numoftrees--;
                     }
                }
             } 
           }
           else if ( direction == 2 ) {
               
                
                if ( (position % columns) == (columns - 1) ){
                //if the direction is east and we are in the rightmost row
                //try again
                }
                else 
                {
                     compare = position + 1;
                     if ( buildhelp(position, compare) ){
                        maze[position].walls[2] = false;
                        maze[compare].walls[3] = false;
                        numoftrees--;
                     }
                }
           }
           else if ( direction == 3 ){
                
                
                if ( (position % columns) == 0 ){
                //if the direction is west and we are in the leftmost row
                //try again
                }
                else 
                {
                     compare = position - 1;
                     if ( buildhelp(position, compare) ){
                        maze[position].walls[3] = false;
                        maze[compare].walls[2] = false;
                        numoftrees--;
                     }
                } 
           }
           else
           {
               cout << "error";
           }     
     }
 
}

bool Maze::buildhelp(int p, int c){
 
     //if two cells have different roots
     //(ie are not part of the same maze)
     //Combine the two trees and return true.
     //If they are in the same tree, return false
     if ( mtree->differ(p,c) )
     {
          mtree->UNION(p,c);
          return true;
     }
     else
     {
         return false;
     }
}


