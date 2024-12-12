/* 
 * File:   WeightedGraph.h
 * Author: Khadiza Akter
 * Created on December 7, 2024, 10:22 AM
 * Purpose: WeightedGraph class specification
 */

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include "Edge.h" // Include the Edge structure

using namespace std;

class WeightedGraph {
private:
    unordered_map<string, vector<Edge>> graph;  // Graph representation

public:
    // Function prototypes
    void connectVertex(string, string, int);  // Add an edge to the graph
    int shortestDistance(string, string);    // Find shortest path using Dijkstra's algorithm
    vector<Edge> minimumSpanningTree();      // Find MST using Prim's algorithm
};


#endif /* WEIGHTEDGRAPH_H */

