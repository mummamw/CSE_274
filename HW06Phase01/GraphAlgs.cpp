#include <algorithm>
#include <vector>
#include "GraphAlgs.h"
#include "Graph.h"
//#include "MatrixGraph.h"

/*
* Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that
* vists every node exactly once (with exception of the first node, which is repeated as the
* last node in the cycle.)
*
* Return value: Return a pair, with the first element being a vector of length n listing the
*  order of the nodes in the cycle (do NOT list the start node twice), and the second element
*  being the length of that path (do NOT forget to include the edge from the last node back to
*  the start node in the total length.
*
* Preconditions:
*     G is undirected.
*     Every pair of nodes u,v  (u != v) has an edge connecting the of weight > 0.
*/

/* Reformated section to understand. 
* Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that
* vists every node exactly once (with exception of the first node, which is repeated as the
* last node in the cycle.)
*
* Return value: Return a pair, 
	first element being a vector (array) of length n listing the order of the nodes in the cycle 
		(do NOT list the start node twice), 
	Second element being the length of that path 
		(do NOT forget to include the edge from the last node back to
*  the start node in the total length.
*
* Preconditions: (asserts)
*     G is undirected.
*     Every pair of nodes u,v  (u != v) has an edge connecting the of weight > 0.
*/

/*
* Suedo Code
* create a pair<vector, edgeWeight>
* create a vector (array)
* while(std::next_permutation(first, last) 
* return pair
*/

/*Hint
* Brute Forceing the TSP use std::next_permutation in <algorithm>
* "Lexicographically" greater permutation
* Works off of returning true or false depending on 
*	-is the one which has all its element sorted in ascending order?
* When returning true it has determined the next higher permuation.
*** The next permuation actually updates your information.
*comp compares - Surprise?
*
*template <class BidirectionalIterator, class Compare>
  bool next_permutation (BidirectionalIterator first,
                         BidirectionalIterator last, Compare comp);
while ( std::next_permutation(myints,myints+3) );
*
* This one makes the most sense to edit with the two parts. Along with compare.
*/

/* Take in Matrix Graph as an array and then use a list to add connections 
* use getAdj to move accrross vector with next permutation?
*/


std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){

	std::pair<std::vector<NodeID>, EdgeWeight> p;

	NodeID* vertexArray = new NodeID[G->size()];

	for (int i = 0; i<G->size(); i++) {
		vertexArray[i] = i;
	}

	EdgeWeight best_weight = std::numeric_limits<double>::max();
	std::vector<NodeID> best_path;

	do {
		std::list<NWPair> node;
		EdgeWeight current_weight = 0.0;
		for(int i = 0; i < G->size(); i++){
		EdgeWeight current = G->weight(vertexArray[i], vertexArray[(i+1)%G->size()]);
		current_weight += current;
	}

	if(current_weight < best_weight){
		best_weight = current_weight;
		best_path.clear();
		for(int i = 0; i < G->size(); i++){
			best_path.push_back(vertexArray[i]);
		}
	}

	} while (std::next_permutation(vertexArray,vertexArray + G->size()));

	p = std::pair<std::vector<NodeID>, EdgeWeight>(best_path, best_weight);

	return p;

}
