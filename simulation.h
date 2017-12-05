//
// Created by Mengqing on 11/14/17.
//

#ifndef XY_SIMULATION_H
#define XY_SIMULATION_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "node.h"
#include "edge.h"

class Simulation {

public:
    double _alpha = 1;
    double _alphaMin = 0.001;
    double _alphaTarget = 0;
    double _alphaDecay = 0;
    double _velocityDecay = 0.6;
    vector<Node> nodes;
    vector<Edge> edges;
    void simulation(const vector<Node*>& nodes, const vector<Edge>& edges);
    void step(const vector<Node*>& nodes, const vector<Edge>& edges);
    void  tick(const vector<Node*>& nodes, const vector<Edge>& edges);
    static void initializeNodes(const vector<Node*>& nodes);
    static double alpha(double _alpha);
    static double alphaMin(double _alphaMin);
    static double alphaDecay(double _alphaDecay);
    static double alphaTarget(double _alphaTarget);
    static double velocityDecay(double _velocityDecay);
    double coord_x(const Node& node);
    double coord_y(const Node& node);
};
#endif //XY_SIMULATION_H
