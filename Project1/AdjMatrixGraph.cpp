#include "AdjMatrixGraph.h"

	// default constructor
AdjMatrixGraph::AdjMatrixGraph( )
{
	numOfVertices = 0;
	maxVertices = MAX_MATRIX_VERTICES;

	vertices = new string[maxVertices];
	
	matrix = new int *[maxVertices];
	for (int i = 0; i < maxVertices; ++i)
		matrix[i] = new int[maxVertices]();
}

	// overloaded constructor
AdjMatrixGraph::AdjMatrixGraph(int totalVertices)
{
	numOfVertices = totalVertices;
	maxVertices = totalVertices * 2;

	vertices = new string[maxVertices];

	matrix = new int *[maxVertices];
	for (int i = 0; i < maxVertices; ++i)
		matrix[i] = new int[maxVertices]();
}

	// createAdjMatrixGraph
void AdjMatrixGraph::createAdjMatrixGraph
				(const vector<vector<string>>& graphData)
{
	// Need to populate array vertices first, to compare later.
	for (int i = 0; i < numOfVertices; ++i)
		vertices[i] = graphData[i].at(0);

	for (int i = 0; i < numOfVertices; ++i)
	{
		int adjVertices = static_cast<int>(graphData[i].size()) - 1;

		for (int j = 1; j <= adjVertices; ++j)
		{
			int k = 0;
			bool found = false;
			while (!found)
			{
				if (vertices[k] == graphData[i].at(j))
					found = true;
				else
					++k;
			}
			matrix[k][i] = 1;
		}
	}
}

	// printVertices
	// Assume the list has at least one vertex.
void AdjMatrixGraph::printVertices() const
{
	cout << "VERTICES: ";
	for (int i = 0; i < numOfVertices; ++i)
		cout << vertices[i] << " ";
}

	// printAllSuccessors
	// Assume the list has at least one vertex.
void AdjMatrixGraph::printAllSuccessors() const
{
	for (int i = 0; i < numOfVertices; ++i)
	{
		cout << "- " << vertices[i] << ": ";
		bool successor = false;
		for (int j = 0; j < numOfVertices; ++j)
		{
			if (matrix[j][i] == 1)
			{
				cout << vertices[j] << " ";
				successor = true;
			}
		}
		if (!successor)
			cout << "No successors";
		cout << endl;
	}
}
