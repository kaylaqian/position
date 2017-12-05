//
// Created by Mengqing on 11/15/17.
//

#include "node.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Node::Node(int id) : id(id) {
  x = rand() % 10000000 / 1000000.0f;
  y = rand() % 10000000 / 1000000.0f;
  vx = rand() % 10000000 / 1000000.0f;
  vy = rand() % 10000000 / 1000000.0f;
}
