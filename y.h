//
// Created by Mengqing on 11/15/17.
//


#ifndef XY_Y_H
#define XY_Y_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "node.h"
#include "edge.h"

class ForceY {
public :
    void static apply(int alpha, vector<Node> nodes);
    static double strength(vector<Node> nodes, int n);
};

#endif //XY_Y_H
