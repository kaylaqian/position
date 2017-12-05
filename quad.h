//
// Created by Mengqing on 11/30/17.
//

#ifndef XY_QUAD_H
#define XY_QUAD_H

#include "node.h"
class quad {
public:
    quad();
    Node* node;
    double x0 = std::numeric_limits<double>::quiet_NaN();
    double y0 = std::numeric_limits<double>::quiet_NaN();
    double x1 = std::numeric_limits<double>::quiet_NaN();
    double y1 = std::numeric_limits<double>::quiet_NaN();
};
#endif //XY_QUAD_H
