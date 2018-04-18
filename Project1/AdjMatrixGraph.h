#ifndef ADJMATRIXGRAPH_H
#define ADJMATRIXGRAPH_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_MATRIX_VERTICES = 20;

class AdjMatrixGraph
{
public:
	AdjMatrixGraph( );
	AdjMatrixGraph(int totalVertices);

	void createAdjMatrixGraph(const vector<vector<string>>& graphData);

	void printVertices() const;
	void printAllSuccessors() const;

	// The Big 5

	// detroyGraph

private:

	string *vertices;		//will point to an array storing labels for vertices
    int **matrix;			//will point to the adjacency matrix
    int maxVertices;		//max number of vertices the graph can hold (capacity)
    int numOfVertices;		//total number of vertices

};

#endif