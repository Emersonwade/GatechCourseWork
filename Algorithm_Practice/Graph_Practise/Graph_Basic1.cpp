#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Graph_Basic1 try to get the adj matrix through the input.
 */


int main(int argc, char const *argv[])
{
    int vertex, edge;
    int ** adjMaxtrix;
    
    cout << "Please input the number of vertex and edge" << endl;
    cin >> vertex >> edge;

    adjMaxtrix = new int * [vertex];
    for (int i = 0; i < vertex; i ++){
        adjMaxtrix[i] = new int [vertex];
        for (int j = 0; j < vertex; j ++){
            adjMaxtrix[i][j] = 0;
        }
    }
    
    cout << "Please input those edge by two vertex" << endl;
    for(int i = 0; i < edge; i ++){
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        if (vertex1 == vertex2 ||
            vertex1 >= vertex || vertex2 >= vertex ||
            adjMaxtrix[vertex1][vertex2] == 1) {
            cout << "WRONG INPUT" << endl;
            i = i - 1;
            continue;
        }
        else {
            adjMaxtrix[vertex1][vertex2] = 1;
        }
    }

    for (int i = 0; i < vertex; i ++){
        for (int j = 0; j < vertex; j ++){
            cout << adjMaxtrix[i][j] << " ";
        }
        cout << endl;
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

