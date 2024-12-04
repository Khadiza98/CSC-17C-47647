#pragma once
/*
 * File:   BShipSetUp.h
 * Author: Khadiza Akter
 * Created on December 02, 2024, 1:50 PM
 * Purpose: Create a graph for the label column
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;


class Graph {
public:
    // Define a structure for a graph node
    struct Node {
        char label;          // Label of the node (e.g., 'A', 'B', ...)
        int edges[10];       // Array to represent edges to other nodes (1: connected, 0: not connected)

        Node() : label(' '), edges{ 0 } {} // Default constructor
    };
    static const int MAX_NODES = 10; // Maximum number of nodes
    Node nodes[MAX_NODES];          // Array of nodes
    void initialize();
    void addEdge(int u, int v);
    char getLabel(int node) const;
    pair<char, char> findMinMaxLabels() const;
};
#endif /* GRAPH_H */
