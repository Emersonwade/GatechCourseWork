#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Graph_Basic3 this is the depth_first_search which creates the topologically order of
the nodes, which use the pre and post number.
 */

struct table_node {
    int node;
    table_node * nextNode;
    int pre;
    int post;
    bool isVisited;
};

int prePostNumber;

void depth_first_search(int node, table_node ** table)
{
    table_node * currentNode = table[node];
    if(currentNode->isVisited)
        return;
    currentNode->isVisited = true;
    currentNode->pre = prePostNumber;
    prePostNumber ++;

    if(currentNode->nextNode != NULL){
        table_node * nextNode = table[node]->nextNode;
        depth_first_search(nextNode->node, table);
        while(nextNode->nextNode != NULL){
            nextNode = nextNode->nextNode;
            depth_first_search(nextNode->node, table);
        }    
    }
    
    currentNode->post = prePostNumber;
    prePostNumber ++;
}

int main(int argc, char const *argv[])
{
    int vertex, edge;
    table_node ** table;

    cout << "Please input the number of vertex and edge" << endl;
    cin >> vertex >> edge;

    prePostNumber = 0;

    table = new table_node *[vertex];
    for(int i = 0; i < vertex; i ++){
        table[i] = new table_node;
        table[i]->node = i;
        table[i]->nextNode = NULL;
        table[i]->isVisited = false;
    }

    cout << "Please input the edges" << endl;
    for(int i = 0; i < edge; i ++){
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        table_node * tempNode = table[vertex1];
        while(tempNode->nextNode != NULL){
            tempNode = tempNode->nextNode;
        }
        table_node * newNode = new table_node;
        tempNode->nextNode = newNode;
        newNode->node = vertex2;
        newNode->nextNode = NULL;    
    }

    for(int i = 0; i < vertex; i++){
        depth_first_search(i, table);
    }

    for(int i = 0; i < vertex; i ++){
        cout << table[i]->post << endl;
    }


    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}


