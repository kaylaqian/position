//
// Created by Mengqing on 11/21/17.
//

#ifndef XY_CENTER_H
#define XY_CENTER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "node.h"
#include "edge.h"

class CenterForce {
public:
    vector<Node>* nodes;
    vector<Edge>* edges;
    static void apply(int x, int y, const vector<Node*>& nodes);

};

#endif //XY_CENTER_H
