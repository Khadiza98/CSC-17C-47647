/* 
 * File:   Edge.h
 * Author: Khadiza Akter
 * Created on December 7, 2024, 10:28 AM
 * Purpose: Edge file specification
 */

#ifndef EDGE_H
#define EDGE_H

#include <string>
using namespace std;

// Structure to represent an edge
struct Edge {
    string source;
    string destination;
    int weight;

    Edge(string s, string d, int w) : source(s), destination(d), weight(w) {}
};


#endif /* EDGE_H */

