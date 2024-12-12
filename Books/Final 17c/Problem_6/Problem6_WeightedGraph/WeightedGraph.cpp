/* 
 * File:   WeightedGraph.cpp
 * Author: Khadiza Akter
 * Created on December 7, 2024, 10:22 AM
 * Purpose: WeightedGraph class implementation
 */

#include "WeightedGraph.h"
#include <climits>
#include <algorithm>

// Function to add an edge to the graph
void WeightedGraph::connectVertex(string source, string destination, int weight) {
    graph[source].push_back(Edge(source, destination, weight));
    graph[destination].push_back(Edge(destination, source, weight));  // Undirected graph
}

// Function to find the shortest distance using Dijkstra's algorithm
int WeightedGraph::shortestDistance(string start, string end) {
    unordered_map<string, int> distances;
    unordered_map<string, bool> visited;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    for (const auto& node : graph) {
        distances[node.first] = INT_MAX;  // Initialize distances to infinity
    }
    distances[start] = 0;
    pq.push({0, start});  // Push start node

    while (!pq.empty()) {
        string current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        if (current == end) break;  // Early stopping

        for (const Edge& edge : graph[current]) {
            int newDist = currentDist + edge.weight;
            if (!visited[edge.destination] && newDist < distances[edge.destination]) {
                distances[edge.destination] = newDist;
                pq.push({newDist, edge.destination});
            }
        }
    }
    return distances[end] == INT_MAX ? -1 : distances[end];
}

// Function to find the minimum spanning tree using Prim's algorithm
vector<Edge> WeightedGraph::minimumSpanningTree() {
    vector<Edge> mst;
    unordered_map<string, bool> visited;

    auto compare = [](Edge& a, Edge& b) { return a.weight > b.weight; };
    priority_queue<Edge, vector<Edge>, decltype(compare)> pq(compare);

    for (const auto& edge : graph.begin()->second) {
        pq.push(edge);
    }
    visited[graph.begin()->first] = true;

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        if (visited[current.destination]) continue;
        visited[current.destination] = true;
        mst.push_back(current);

        for (const Edge& edge : graph[current.destination]) {
            if (!visited[edge.destination]) {
                pq.push(edge);
            }
        }
    }
    return mst;
}


