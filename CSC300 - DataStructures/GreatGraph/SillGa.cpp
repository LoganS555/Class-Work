// CSC 300 Fall 2021
/*
 - C++ class for introducing graphs & graph algorithms
 - for simplification, we have the following restrictions:
    - less than 100 nodes, so matrix can be static allocation
    - no self edges
    - all graph description files will be weighted
    - all weights > 0

 - node order
    print out the nodes, on 1 line, in the order dictated by algorithm
 - spanning tree
    print out edges     start-end   in the order dictated by algorithm

Graph Description File format
  Number of Nodes
  Number of Edges
  Source  Destination  Weight     [ for each edge ]

*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class graph
{
        public:
                graph( ifstream& file );   // constructor
                                   // fill graph from data file
                                   // file is already open
                //void bfs( int x );         // breadth-first node order
                //void bfssp( int x );       // breadth-first spanning tree
                //void dfs( int x );         // depth-first node order
                //void dfssp( int x );       // depth-first spanning tree
                void mprint();             // print representation
        private:
                int edges;
                int vertices;
                int matrix[100][100] = {0};
};


graph::graph( ifstream& file )
{
        file >> vertices;
        file >> edges;
        int x,y,w;
        while ( !file.eof() )
        {
                file >> x;
                file >> y;
                file >> w;
                matrix[x][y] = w;
                matrix[y][x] = w;
        }
}
void graph::mprint()
{
        int k = 1, i;
        while ( k <= vertices )
        {
                i = 1;
                while ( i <= vertices )
                {
                        cout << setw(2) << matrix[k][i] << " ";
                        i++;
                }
                cout << endl;
                k++;
        }

}

int main( int argc, char *argv[] )
{
        ifstream ifp;

        //checking to see if file was entered on command line
        if ( argc != 2 )
        {
                cout << "File was not entered\n";
                return 2;
        }

        ifp.open( argv[1] );

        // checking to see if file was opened successfully
        if( ! ifp.is_open() )
        {
                cout << "File could not be opened\n";
                return 3;
        }

        //create graph based on graph description file
        graph g( ifp );

        //print the matrix
        g.mprint();
        cout << endl << endl;

        /*
        //ask for starting location
        cout << "Enter the starting location: ";
        cin >> location;

        // calculate DFS
        g.dfs( location );
        cout << endl << endl;

        //calculate DFS-SP
        g.dfssp( location );
        cout << endl << endl;

        //calculate BFS
        g.bfs( location );
        cout << endl << endl;

        //calculate BFS-SP
        g.bfssp( location );
        cout << endl << endl;

        */

        return 0;
}
