//
// Created by Mengqing on 11/21/17.
//

#ifndef XY_MANYBODY_H
#define XY_MANYBODY_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "node.h"
#include "quad.h"
#include "Quadtree.h"

using namespace std;
class Charge {
public:
    const vector<Node*>& nodes;
    int n = nodes.size();
    double strengths[];
    void force(vector<Node*>& nodes, double alpha, vector<Quadtree*>& tree);
    void apply(Node* node, double x1, double x2, double alpha);
    void initialize(vector<Node*>& nodes);
    Quadtree Charge::quadtree(vector<Node*>& nodes, int x, int y);
    void accumulate(vector<quad> quad);
    double strength(vector<Node*>& nodes, int n);
};
#endif //XY_MANYBODY_H
