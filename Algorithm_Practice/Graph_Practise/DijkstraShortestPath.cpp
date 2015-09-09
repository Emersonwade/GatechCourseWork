#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
This is the Dijkstra's shortest Path Alogrithm.
 */

struct table_node {
    int node;
    table_node * nextNode;
    int pre;
    int distance;
    int weight;
};

int prePostNumber;

void dijkstra(vector<int>visited, vector<int>unvisited, table_node ** table){
    int cNodeNumber = (int)visited.back();

    table_node * currentNode = table[cNodeNumber];
    while(currentNode->nextNode != NULL){
        currentNode = currentNode->nextNode;
    }
    table_node * newNode = new table_node;
    currentNode->nextNode = newNode;
    newNode->nextNode = NULL;    
}

// void depth_first_search(int node, table_node ** table)
// {
//     table_node * currentNode = table[node];
//     if(currentNode->isVisited)
//         return;
//     currentNode->isVisited = true;
//     currentNode->pre = prePostNumber;
//     prePostNumber ++;

//     if(currentNode->nextNode != NULL){
//         table_node * nextNode = table[node]->nextNode;
//         depth_first_search(nextNode->node, table);
//         while(nextNode->nextNode != NULL){
//             nextNode = nextNode->nextNode;
//             depth_first_search(nextNode->node, table);
//         }    
//     }
    
//     currentNode->post = prePostNumber;
//     prePostNumber ++;
// }

int main(int argc, char const *argv[])
{
    int vertex, edge;
    table_node ** table;

    int startNode;
    vector<int> visited;
    vector<int> unvisited;

    cout << "Please input the number of vertex and edge" << endl;
    cin >> vertex >> edge;

    prePostNumber = 0;

    table = new table_node *[vertex];
    for(int i = 0; i < vertex; i ++){
        table[i] = new table_node;
        table[i]->node = i;
        table[i]->nextNode = NULL;
        table[i]->pre = -1;
        table[i]->distance = -1;
    }

    cout << "Please input the start node" << endl;
    cin >> startNode;
    for(int i = 0; i < vertex; i ++){
        if(i != startNode)
            unvisited.push_back(i);
        else {
            visited.push_back(i);
        }
    }
    cout << "Please input the edges and edgeWeight" << endl;
    for(int i = 0; i < edge; i ++){
        int vertex1, vertex2, edgeWeight;
        cin >> vertex1 >> vertex2 >> edgeWeight;
        table_node * tempNode = table[vertex1];
        while(tempNode->nextNode != NULL){
            tempNode = tempNode->nextNode;
        }
        table_node * newNode = new table_node;
        tempNode->nextNode = newNode;
        newNode->node = vertex2;
        newNode->weight = edgeWeight;
        newNode->nextNode = NULL;    
    }


    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}


