//
// Created by Mengqing on 12/1/17.
//

#ifndef XY_QUADTREE_H
#define XY_QUADTREE_H

#include "node.h"

class Quadtree {
public:
    double x;
    double y;
    double x0 = std::numeric_limits<double>::quiet_NaN();
    double y0 = std::numeric_limits<double>::quiet_NaN();
    double x1 = std::numeric_limits<double>::quiet_NaN();
    double y1 = std::numeric_limits<double>::quiet_NaN();
    Node* root;
};
#endif //XY_QUADTREE_H
