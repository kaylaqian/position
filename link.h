//
// Created by Mengqing on 11/15/17.
//

#ifndef XY_LINK_H
#define XY_LINK_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "node.h"
#include "edge.h"

class LinkForce {
public:
    vector<Node> nodes;
    vector<Edge> edges;
    int n;
    int m;
    double _iteration = 1;
    double _distance = 30;
    void apply(double alpha, const vector<Node*>& nodes, const vector<Edge>& edges);
    static double strength(Edge edge);
    static double distance(double _distance);
    double iteration(double _iteration);
};
#endif //XY_LINK_H
