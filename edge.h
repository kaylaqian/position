//
// Created by Mengqing on 11/15/17.
//

#ifndef XY_EDGE_H
#define XY_EDGE_H

#include "node.h"
#include <string>
#include <map>

using namespace std;

class Edge {

public:
    Edge(Node* source, Node* target);
  Node* source;
  Node* target;
};

#endif //XY_EDGE_H
