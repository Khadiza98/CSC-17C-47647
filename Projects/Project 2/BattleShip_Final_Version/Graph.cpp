/*
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on December 02, 2024, 10:02 PM
 * Purpose: Implementation file for Graph class
 */
#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;
#include "Graph.h"

// Initialize the graph with labels
void Graph::initialize() {
    for (int i = 0; i < MAX_NODES; ++i) {
        nodes[i].label = 'A' + i; // Assign labels 'A' to 'J'
    }
}

// Add an edge between two nodes
void Graph::addEdge(int u, int v) {
    if (u >= 0 && u < MAX_NODES && v >= 0 && v < MAX_NODES) {
        nodes[u].edges[v] = 1; // Mark as connected
        nodes[v].edges[u] = 1; // For undirected graph
    }
}

// Get the label of a node
char Graph::getLabel(int node) const {
    if (node >= 0 && node < MAX_NODES) {
        return nodes[node].label;
    }
    return '?'; // Return '?' for invalid node
}

// Find the minimum and maximum labels
pair<char, char> Graph::findMinMaxLabels() const {
    char minLabel = nodes[0].label;
    char maxLabel = nodes[0].label;

    for (int i = 1; i < MAX_NODES; ++i) {
        if (nodes[i].label < minLabel) {
            minLabel = nodes[i].label;
        }
        if (nodes[i].label > maxLabel) {
            maxLabel = nodes[i].label;
        }
    }
    return { minLabel, maxLabel };
}


