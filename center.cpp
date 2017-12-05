//
// Created by Mengqing on 11/21/17.
//
#include "center.h"

void CenterForce::apply(int x, int y, const vector<Node*>& nodes) {
    int n = nodes.size();

    int sx = 0;
    int sy = 0;
    for(int i = 0; i < n; i++) {
        Node* node = nodes[i];
        sx += node->x;
        sy += node->y;
    }
    for(int i = 0/*, sx= sx/n - x, sy = sy/n -y*/; i < n; ++i) {
        Node* node = nodes[i];
        sx= sx/n - x;
        sy = sy/n -y;
        node->x -= sx;
        node->y -= sy;
    }
}