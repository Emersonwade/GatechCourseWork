#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Graph_Basic1 try to get the adj table through the adj matrix.
 */

struct table_node {
    int node;
    table_node * nextNode;
};

int main(int argc, char const *argv[])
{
    int vertex;
    table_node ** table;

    cout << "Please input the number of vertex" << endl;
    cin >> vertex;

    table = new table_node *[vertex];
    for(int i = 0; i < vertex; i ++){
        table[i] = new table_node;
        table[i]->node = i;
        table[i]->nextNode = NULL;
    }

    cout << "Please input the matrix" << endl;
    for(int i = 0; i < vertex; i ++){
        for(int j = 0; j < vertex; j ++){
            int isEdge;
            cin >> isEdge;
            if (isEdge == 1){
                table_node * tempNode = table[i];
                while(tempNode->nextNode != NULL){
                    tempNode = tempNode->nextNode;
                }
                table_node * newNode = new table_node;
                tempNode->nextNode = newNode;
                newNode->node = j;
                newNode->nextNode = NULL;    
            }
        }
    }

    for(int i = 0; i < vertex; i ++){
        table_node * tempNode = table[i]->nextNode;
        cout << tempNode->node << " ";
        while(tempNode->nextNode != NULL){
            tempNode = tempNode->nextNode;
            cout << tempNode->node << " ";
        }
        cout << endl;
    }


    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

