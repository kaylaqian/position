//
// Created by Mengqing on 11/15/17.
//

#ifndef XY_NODE_H
#define XY_NODE_H

#include <string>
#include <stdlib.h>

class Node {
public:
  Node(int id);
  int id;
  double x;
  double y;
  double fx = std::numeric_limits<double>::quiet_NaN();
  double fy = std::numeric_limits<double>::quiet_NaN();
  double vx;
  double vy;
};

#endif //XY_NODE_H
