/*
	Badajoz, Severiano

	CS A200
	April 18, 2018

	Lab 04a
*/

#include "AdjMatrixGraph.h"

// copy constructor
AdjMatrixGraph::AdjMatrixGraph(const AdjMatrixGraph& other) {
	maxVertices = other.maxVertices;
	numOfVertices = other.numOfVertices;

	vertices = new string[maxVertices];
	matrix = new int*[maxVertices];
	for (int i = 0; i < maxVertices; ++i)
	{
		vertices[i] = other.vertices[i];
		matrix[i] = new int[maxVertices];
		for (int j = 0; j < maxVertices; ++j)
			matrix[i][j] = other.matrix[i][j];
	}
}

// move constructor
AdjMatrixGraph::AdjMatrixGraph(AdjMatrixGraph&& other) {
	maxVertices = other.maxVertices;
	numOfVertices = other.numOfVertices;

	vertices = other.vertices;
	matrix = other.matrix;

	other.vertices = nullptr;
	other.matrix = nullptr;
	other.maxVertices = 0;
	other.numOfVertices = 0;
}


// overloaded assignment operator
AdjMatrixGraph& AdjMatrixGraph::operator=(const AdjMatrixGraph& other) {
	if (&other != this) {
		if (maxVertices != other.maxVertices) {
			for (int i = 0; i < maxVertices; i++) {
				delete[] matrix[i];
				matrix[i] = nullptr;
			}
			maxVertices = other.maxVertices;

			delete[] matrix;
			matrix = new int*[maxVertices];

			for (int i = 0; i < maxVertices; i++)
				matrix[i] = new int[maxVertices];

			delete[] vertices;
			vertices = new string[maxVertices];
		}

		numOfVertices = other.numOfVertices;
		for (int i = 0; i < maxVertices; i++) {
			vertices[i] = other.vertices[i];
			for (int j = 0; j < maxVertices; j++)
				matrix[i][j] = other.matrix[i][j];

		}
	}
	else cerr << "Incorrect attempt to assign matrix to itself" << endl;

	return *this;
}

// move assignment operator
AdjMatrixGraph& AdjMatrixGraph::operator=(AdjMatrixGraph&& other) {
	if (&other != this) {
		delete[] vertices;
		vertices = other.vertices;

		for (int i = 0; i < maxVertices; i++) {
			delete[] matrix[i];
			matrix[i] = nullptr;
		}

		delete matrix;
		matrix = other.matrix;
		numOfVertices = other.numOfVertices;
		maxVertices = other.maxVertices;

		other.numOfVertices = 0;
		other.maxVertices = 0;
		other.vertices = nullptr;
		other.matrix = nullptr;
	}
	return *this;
}

// destructor
AdjMatrixGraph::~AdjMatrixGraph() {
	for (int i = 0; i < maxVertices; ++i)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}

	delete[] matrix;
	matrix = nullptr;
	delete[] vertices;
	vertices = nullptr;
	numOfVertices = 0;
	maxVertices = 0;
}

// destroyGraph
void AdjMatrixGraph::destroyGraph() {
	delete[] vertices;
	vertices = new string[maxVertices]();
	for (int i = 0; i < numOfVertices; ++i) {
		delete[] matrix[i];
		matrix[i] = new int[maxVertices]();
	}

	numOfVertices = 0;
}