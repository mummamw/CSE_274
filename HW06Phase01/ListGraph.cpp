/*
*Michael Mumma 
*ListGraph.cpp
*Implemention of a Listgraph
*/


#include <cassert>
#include "ListGraph.h"

//creates a new list to add for how many nodes there are
ListGraph::ListGraph(int numNodes){
    num_edges = 0;
    for (int i = 0; i < numNodes; i++){
        EList list;                      
        edgeList.push_back(list);
    }
}

//Deconstructor empty never using new.
ListGraph::~ListGraph(){
}

// Modifiers
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	std::list<NWPair>::iterator it = edgeList[u].begin();
	while (it != edgeList[u].end()){
		assert(v != it->first);
		it++;
	}
	edgeList[u].push_back(std::make_pair(v, weight));
	edgeList[v].push_back(std::make_pair(u, weight));
	num_edges++;
}

// Inspectors
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	EdgeWeight e = 0;
	std::list<NWPair>::const_iterator it = edgeList[u].begin();
	while (it != edgeList[u].end()){
		if (v == it->first){
			e = it->second;
			break;
		}
		it++;
	}
	return e;
}
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	return edgeList[u];
}
unsigned ListGraph::degree(NodeID u) const{ 
	return edgeList[u].size(); 
}

unsigned ListGraph::size() const{ 
	return edgeList.size(); 
}

unsigned ListGraph::numEdges() const{ 
	return num_edges; 
}

