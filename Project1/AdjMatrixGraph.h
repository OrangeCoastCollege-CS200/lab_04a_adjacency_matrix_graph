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

	//Overloaded Copy Constructor
	AdjMatrixGraph(const AdjMatrixGraph& other);

	//Overloaded Move Constructor
	AdjMatrixGraph(AdjMatrixGraph&& other);

	//Overrided Assignement Operator
	AdjMatrixGraph& operator=(const AdjMatrixGraph& other);

	//Overrided Move assignment Operator
	AdjMatrixGraph& operator=(AdjMatrixGraph&& other);

	//Destructor
	~AdjMatrixGraph();

	// destroyGraph
	void destroyGraph();


private:

	string *vertices;		//will point to an array storing labels for vertices
    int **matrix;			//will point to the adjacency matrix
    int maxVertices;		//max number of vertices the graph can hold (capacity)
    int numOfVertices;		//total number of vertices

};

#endif