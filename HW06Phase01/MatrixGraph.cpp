/*
*Michael Mumma
*matrixGraph.cpp
*Implemention of a MatrixGraph
*/

#include <vector>
//#include "Graph.h"
#include "MatrixGraph.h"
#include <utility>
#include <cassert>

//create a square matrix
MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges = 0;
	for (int i = 0; i < num_nodes; i++){
		std::vector<EdgeWeight> row;
		for (int j = 0; j < num_nodes; j++){
			row.push_back(0);
		}
		M.push_back(row);
	}
}

//Deconstructor that I wont touch
MatrixGraph::~MatrixGraph(){
}

// Modifiers
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	assert((0 <= u <= MatrixGraph::size()) && (0 <= v <= MatrixGraph::size()) && (u != v) && (weight>0) && (M[u][v] == 0) && (M[v][u] == 0));
	//THIS WAS THE PROBLEM, has M[u][v] for both sides so it was only adding it to one side.
	M[u][v] = weight;
	M[v][u] = weight;
	num_edges++;
}

// Inspectors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	assert((0 <= u <= MatrixGraph::size()) && (0 <= v <= MatrixGraph::size()));
	if (M[u][v] == M[v][u]) return M[u][v];
}

//Retrun a list of NodeID and Edge wight pairs from this node
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	assert(0 <= u <= MatrixGraph::size());
	EList list;
	for (int i = 0; i<M.size(); i++){
		EdgeWeight weight = M[u][i];
		if (weight != 0){
			list.push_back(std::make_pair(i, weight));
		}
	}
	return list;
}

//return dregree of a node 
//goes through and adds all the weights there are.
unsigned MatrixGraph::degree(NodeID u) const{
	assert(0 <= u <= MatrixGraph::size());
	int tmp = 0;
	for (int i = 0; i<M.size(); i++){
		EdgeWeight weight = M[u][i];
		if (weight != 0){
			tmp++;
		}
	}
	return tmp;
}

//return the size
unsigned MatrixGraph::size() const{ return M.size(); }

//return the variable that is inside
unsigned MatrixGraph::numEdges() const{ return num_edges; }
