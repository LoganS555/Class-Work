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
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

class graph
{
        public:
                graph( ifstream& file );   // constructor
                                   // fill graph from data file
                                   // file is already open
                void dijkstra ( int x );
                void prim ( int x );
                void kruskal ();
                void bfs( int x );         // breadth-first node order
                void bfssp( int x );       // breadth-first spanning tree
                void dfs( int x );         // depth-first node order
                void dfssp( int x );       // depth-first spanning tree
                void mprint();             // print representation
                void shortestDij();
                void floydwarshall();
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

void graph::floydwarshall()
{
        int dist[vertices+1][vertices+1], i, j, k;
        int     infinity = 100000;

        for ( i = 1; i <= vertices; i++ )
        {
                for ( j = 1; j <= vertices; j++ )
                {
                        if (matrix[i][j] == 0 && i != j )
                                dist[i][j] = infinity;
                        else
                                dist[i][j] = matrix[i][j];
                }
        }
        for (k = 1; k <= vertices; k++)
        {
        // Pick all vertices as source one by one
                for (i = 1; i <= vertices; i++)
                {
            // Pick all vertices as destination for the
            // above picked source
                        for (j = 1; j <= vertices; j++)
                        {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != 0 && dist[i][k] != 0))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
        for ( k = 1; k <= vertices; k++ )
        {
                for ( i = 1; i <= vertices; i++ )
                        cout  << setw(2) << dist[k][i] << " ";
                cout << endl;
        }
}

void graph::shortestDij()
{
        int cost[vertices+1];
        int marked[vertices+1] = {0};
        int apsp[vertices+1][vertices+1] = {0};
        int finished,i;
        int k,lowest,j = 1;

        for ( i = 1; i <= vertices; i++ )
        {
                finished = 0;
                for ( k = 1; k <= vertices; k++ )
                {
                        cost[k] = 10000;
                        marked[k] = 0;
                }
                j = i;
                while( finished != vertices)
                {
                        lowest = 10000;
                        if ( finished == 0 )
                        {
                                cost[i] = 0;
                                marked[i] = 1;
                                finished++;
                        }
                        else
                        {
                                for ( k = 1; k <= vertices; k++ )
                                {
                                        if ( marked[k] == 0 && cost[k] < lowest )
                                        {
                                                lowest = cost[k];
                                                j = k;
                                        }
                                }
                                finished++;
                                marked[j] = 1;
                        }
                        for ( k = 1; k <= vertices; k++ )
                        {
                                if ( marked[k] == 0 && matrix[j][k] != 0)
                                {
                                        if ( (matrix[j][k] + cost[j]) < cost[k] )
                                                cost[k] = (matrix[j][k] + cost[j]);
                                }
                        }
                }
                for ( j = 1; j <= vertices; j++ )
                        apsp[i][j] = cost[j];
        }
        for ( k = 1; k <= vertices; k++ )
        {
                for ( i = 1; i <= vertices; i++ )
                        cout << setw(2) << apsp[k][i] << " ";
                cout << endl;
        }
}

void graph::dijkstra ( int x )
{
        int cost[vertices+1];
        int marked[vertices+1] = {0};
        int finished = 0,i = x;
        int k,lowest;
        for ( k = 1; k <= vertices; k++ )
                cost[k] = 10000;

        while( finished != vertices)
        {
                lowest = 10000;
                if ( finished == 0 )
                {
                        cost[i] = 0;
                        marked[i] = 1;
                        finished++;
                }
                else
                {
                        for ( k = 1; k <= vertices; k++ )
                        {
                                if ( marked[k] == 0 && cost[k] < lowest )
                                {
                                        lowest = cost[k];
                                        i = k;
                                }
                        }
                        finished++;
                        marked[i] = 1;
                }
                for ( k = 1; k <= vertices; k++ )
                {
                        if ( marked[k] == 0 && matrix[i][k] != 0)
                        {
                                if ( (matrix[i][k] + cost[i]) < cost[k] )
                                        cost[k] = (matrix[i][k] + cost[i]);
                        }
                }
                cout << "Set " << i << " to final." << endl;
                for ( k = 1; k <= vertices; k++ )
                {
                        cout << k << ": " << setw(5) << cost[k] << endl;
                }

                cout << endl;
        }
}

void graph::prim ( int x )
{
        int marked[vertices+1] = {0};
        int     maCpy[100][100];
        memcpy(maCpy,matrix,100*100*sizeof(int));
        int k,i;
        int finished = 1;
        int shortest, curr = x, next;
        int total = 0;
        marked[x] = 1;
        while ( finished != vertices )
        {
                shortest = 10000;
                for ( k = 1; k <= vertices; k++ )
                {
                        for ( i = 1; i <= vertices; i++ )
                        {
                                if ( maCpy[k][i] < shortest && maCpy[k][i] != 0 && marked[k] == 1 && marked[i] == 0)
                                {
                                        shortest = maCpy[k][i];
                                        next = i;
                                        curr = k;
                                }
                        }
                }
                total += maCpy[curr][next];
                cout << curr << " - " << next << " " << shortest << endl;
                maCpy[curr][next] = 0;
                maCpy[next][curr] = 0;
                marked[curr] = 1;
                marked[next] = 1;
                curr = next;
                finished++;
        }
        cout << endl;
        cout << "Total Cost: " << total << endl;
}

void graph::kruskal ( )
{
        int marked[vertices+1] = {0};
        int maCpy[100][100];
        memcpy(maCpy,matrix,100*100*sizeof(int));
        int k,i, finished = 1, total = 0;
        int shortest = 10000, sRow, sCol;
        while ( finished != vertices )
        {
                shortest = 10000;
                for ( k = 1; k <= vertices; k++ )
                {
                        for ( i = 1; i <= vertices; i++ )
                        {
                                if ( maCpy[k][i] < shortest && maCpy[k][i] != 0 )
                                {
                                        if ( marked[k] != marked[i] )
                                        {
                                                shortest = maCpy[k][i];
                                                sRow = k;
                                                sCol = i;
                                        }
                                        else if ( marked[k] == 0 && marked[i] == 0 )
                                        {
                                                shortest = maCpy[k][i];
                                                sRow = k;
                                                sCol = i;
                                        }
                                }
                        }
                }
                if ( marked[sRow] == 0 && marked[sCol] == 0 )
                {
                        marked[sRow] = sRow;
                        marked[sCol] = sRow;
                }
                else if ( marked[sRow] == 0 && marked[sCol] != 0 )
                {
                        marked[sRow] = marked[sCol];
                }
                else if ( marked[sRow] != 0 && marked[sCol] == 0 )
                {
                        marked[sCol] = marked[sRow];
                }
                else
                {
                        for ( k = 1; k <= vertices; k++ )
                        {
                                if ( marked[k] != 0 && marked[k] == marked[sCol] )
                                        marked[k] = marked[sRow];
                        }
                }
                finished++;
                total += maCpy[sRow][sCol];
                cout << sRow << " - " << sCol << " " << shortest << endl;
        }
        cout << "Total: " << total << endl;
}

void graph::bfs ( int x )
{
        queue<int> q;
        int v,i;
        int mark[vertices+1] = {0};

        q.push(x);
        while ( ! q.empty() )
        {
                v = q.front();
                q.pop();
                if ( mark[v] != 1 )
                {
                        cout << v << " ";
                        mark[v] = 1;
                }
                for ( i = 1; i <= vertices; i++ )
                {
                        if (matrix[v][i] > 0 && mark[i] == 0 )
                                q.push(i);
                }
        }
}

void graph::bfssp ( int x )
{
        queue<int> q1;
        queue<int> q2;
        int v,w,i;
        int mark[vertices+1] = {0};

        for ( i = 1; i <= vertices; i++ )
        {
                if (matrix[x][i] > 0 && mark[i] == 0 )
                {
                        q1.push(x);
                        q2.push(i);
                }
        }
        while ( !q1.empty() && !q2.empty() )
        {
                v = q1.front();
                q1.pop();
                w = q2.front();
                q2.pop();
                if ( mark[v] == 0 || mark[w] == 0)
                {
                        cout << "(" << v << ", " << w << ") ";
                        mark[v] = 1;
                        mark[w] = 1;
                }
                for ( i = 1; i <= vertices; i++ )
                {
                        if (matrix[w][i] > 0 && mark[i] == 0 )
                        {
                                q1.push(w);
                                q2.push(i);
                        }
                }
        }
}

void graph::dfs ( int x )
{
        stack<int> s;
        int v,i;
        int mark[vertices+1] = {0};

        s.push(x);
        while ( ! s.empty() )
        {
                v = s.top();
                s.pop();
                if ( mark[v] != 1 )
                {
                        cout << v << " ";
                        mark[v] = 1;
                }
                for ( i = vertices; i >= 1; i-- )
                {
                        if (matrix[v][i] > 0 && mark[i] == 0 )
                                s.push(i);
                }
        }
}

void graph::dfssp ( int x )
{
        stack<int> s1;
        stack<int> s2;
        int v,w,i;
        int mark[vertices+1] = {0};

        for ( i = vertices; i >= 1; i-- )
        {
                if (matrix[x][i] > 0 && mark[i] == 0 )
                {
                        s1.push(x);
                        s2.push(i);
                }
        }
        while ( !s1.empty() && !s2.empty() )
        {
                v = s1.top();
                s1.pop();
                w = s2.top();
                s2.pop();
                if ( mark[v] == 0 || mark[w] == 0)
                {
                        cout << "(" << v << ", " << w << ") ";
                        mark[v] = 1;
                        mark[w] = 1;
                }
                for ( i = vertices; i >= 1; i-- )
                {
                        if (matrix[w][i] > 0 && mark[i] == 0 )
                        {
                                s1.push(w);
                                s2.push(i);
                        }
                }
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
                        cout << setw(3) << matrix[k][i] << " ";
                        i++;
                }
                cout << endl;
                k++;
        }

}

int main( int argc, char *argv[] )
{
        ifstream ifp;
        int location;
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

        //ask for starting location
        cout << "Enter the starting location: ";
        cin >> location;

        // calculate DFS
        cout << "DFS:" << endl;
        g.dfs( location );
        cout << endl << endl;

        //calculate DFS-SP
        cout << "DFS ST:" << endl;
        g.dfssp( location );
        cout << endl << endl;

        //calculate BFS
        cout << "BFS:" << endl;
        g.bfs( location );
        cout << endl << endl;

        //calculate BFS-SP
        cout << "BFS ST:" << endl;
        g.bfssp( location );
        cout << endl << endl;

        cout << "Dijkstra:" << endl;
        g.dijkstra ( location );
        cout << endl << endl;

        cout << "Prim:" << endl;
        g.prim ( location );
        cout << endl << endl;

        cout <<"Kruskal:" << endl;
        g.kruskal ( );
        cout << endl << endl;

        cout << "APSP Dijkstra:" << endl;
        g.shortestDij ( );
        cout << endl << endl;

        cout << "APSP Floyd-Warshall:" << endl;
        g.floydwarshall ( );
        cout << endl << endl;

        return 0;
}
