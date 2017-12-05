//
// Created by Mengqing on 11/15/17.
//

#ifndef XY_X_H
#define XY_X_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "node.h"
#include "edge.h"

class ForceX {
public :
    static void apply(int alpha, vector<Node*>& nodes);
    static double strength(vector<Node*>& nodes, int n);
};

#endif //XY_X_H
