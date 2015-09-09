#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
First try to get the adj matrix through the input.
 */

struct treeNode{
    int node;
    int rank;
    treeNode * parent;
    vector<treeNode*> children;
    bool isvisited;
};

struct edgeNode{
    int vertex1;
    int vertex2;
    int weight;
};

treeNode* find(treeNode * node){
    treeNode * parent = node;
    while(parent->parent != NULL){
        parent = parent->parent;
    }
    return parent;
}

void unionNode(treeNode * node1, treeNode * node2){
    treeNode* parent1 = find(node1);
    treeNode* parent2 = find(node2);
    if(parent1->rank >= parent2->rank){
        parent2->parent = parent1;
        parent1->children.push_back(parent2);
        if(parent1->rank == parent2->rank){
            parent1->rank ++;
        }
    }
    else{
        parent1->parent = parent2;
        parent2->children.push_back(parent1);
    }
}

bool edgeNodeCompare(edgeNode * e1, edgeNode * e2)
{
    return e1->weight <= e2->weight;
}

bool treeNodeCompare(treeNode * t1, treeNode * t2)
{
    return t1->rank >= t2->rank;
}

int main(int argc, char const *argv[])
{
    int vertex, edge;
    int ** adjMaxtrix;
    treeNode ** treeNodeArray;
    edgeNode ** edgeNodeArray;
    
    cout << "Please input the number of vertex and edge" << endl;
    cin >> vertex >> edge;

    adjMaxtrix = new int * [vertex];
    treeNodeArray = new treeNode* [vertex];
    for (int i = 0; i < vertex; i ++){
        adjMaxtrix[i] = new int [vertex];
        for (int j = 0; j < vertex; j ++){
            adjMaxtrix[i][j] = -1;
        }

        treeNodeArray[i] = new treeNode;
        treeNodeArray[i]->node = i;
        treeNodeArray[i]->parent = NULL;
        treeNodeArray[i]->rank = 0;
        treeNodeArray[i]->isvisited = false;
    }

    edgeNodeArray = new edgeNode *[edge];
    cout << "Please input those edge by two vertex and edgeWeight" << endl;
    for(int i = 0; i < edge; i ++){
        int vertex1, vertex2, edgeWeight;
        cin >> vertex1 >> vertex2 >> edgeWeight;
        if (vertex1 == vertex2 ||
            vertex1 >= vertex || vertex2 >= vertex ||
            adjMaxtrix[vertex1][vertex2] != -1) {
            cout << "WRONG INPUT" << endl;
            i = i - 1;
            continue;
        }
        else {
            adjMaxtrix[vertex1][vertex2] = edgeWeight;
            edgeNodeArray[i] = new edgeNode;
            edgeNodeArray[i]->vertex1 = vertex1;
            edgeNodeArray[i]->vertex2 = vertex2;
            edgeNodeArray[i]->weight = edgeWeight;
        }
    }
    
    sort(edgeNodeArray, edgeNodeArray + edge, edgeNodeCompare);

    for(int i = 0; i < edge; i ++){
        treeNode* vertex1 = treeNodeArray[edgeNodeArray[i]->vertex1];
        treeNode* vertex2 = treeNodeArray[edgeNodeArray[i]->vertex2];

        if(find(vertex1)->node != find(vertex2)->node){
            unionNode(vertex1, vertex2);
        }
    }

    for(int i = 0; i < edge; i ++){
        cout << edgeNodeArray[i]->vertex1 << " " << edgeNodeArray[i]->vertex2 << " " << edgeNodeArray[i]->weight << endl;
    }

    for (int i = 0; i < vertex; i ++){
        for (int j = 0; j < vertex; j ++){
            cout << adjMaxtrix[i][j] << " ";
        }
        cout << endl;
    }

    int spacecount = 0;
    cout << "MST is " << endl;
    sort(treeNodeArray, treeNodeArray + vertex, treeNodeCompare);
    for (int i = 0; i < vertex; i ++){
        if(!treeNodeArray[i]->isvisited){
            for(int t = 0; t < spacecount; t ++)
                cout << " ";
            cout << treeNodeArray[i]->node << endl;
            spacecount ++;
            treeNodeArray[i]->isvisited = true;

            for(vector<treeNode*>::iterator j = (treeNodeArray[i]->children).begin(); j != (treeNodeArray[i]->children).end(); j ++){
                for(int t = 0; t < spacecount; t ++)
                    cout << " ";
                cout << (*j)->node << endl;
                (*j)->isvisited = true;
            }
            spacecount ++;
        }
    }

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

