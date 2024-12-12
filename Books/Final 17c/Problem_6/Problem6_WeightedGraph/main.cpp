/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on December 05, 2024, 12:46 AM
 * Purpose: Developing a program as a check to find (a)the shortest distance
 *          between ORD and LAX. (b)the shortest distance between JFK and SFO.
 *          (c)the minimum spanning tree.
 */

//System Libraries
#include <iostream> //Input/Output Library
using namespace std;//STD Name-space where Library is compiled

#include "WeightedGraph.h"

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    WeightedGraph graph;
    int distance_a = 0;
    int distance_b = 0;
    int totalWeight = 0;

    // Add edges to the graph
    graph.connectVertex("SFO", "BOS", 2703);
    graph.connectVertex("SFO", "ORD", 1847);
    graph.connectVertex("ORD", "BOS", 868);
    graph.connectVertex("ORD", "JFK", 743);
    graph.connectVertex("JFK", "BOS", 189);
    graph.connectVertex("SFO", "DFW", 1465);
    graph.connectVertex("DFW", "ORD", 803);
    graph.connectVertex("DFW", "MIA", 1124);
    graph.connectVertex("MIA", "JFK", 1093);
    graph.connectVertex("MIA", "BOS", 1257);
    graph.connectVertex("SFO", "LAX", 338);
    graph.connectVertex("LAX", "DFW", 1234);
    graph.connectVertex("LAX", "MIA", 2341);

    // Find the shortest distance between ORD and LAX
    distance_a = graph.shortestDistance("ORD", "LAX");
    cout << "The Shortest distance between ORD and LAX: "
         << distance_a << " miles" << endl;

    // Find the shortest distance between JFK and SFO
    distance_b = graph.shortestDistance("JFK", "SFO");
    cout << "The Shortest distance between JFK and SFO: " 
         << distance_b << " miles" << endl;

    // Find the minimum spanning tree
    vector<Edge> mst = graph.minimumSpanningTree();
    cout << "Minimum Spanning Tree (Edges and Weights):" << endl;
    for (const Edge& edge : mst) {
        cout << edge.source << " --(" << edge.weight << ")-- "
             << edge.destination << endl;
        totalWeight += edge.weight;
    }
    cout << "The Total Weight of Minimum Spanning Tree: " << totalWeight << endl;
    
    // Exit the program
    return 0;
}
