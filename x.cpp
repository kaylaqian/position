//
// Created by Mengqing on 11/15/17.
//

#include "x.h"

void ForceX::apply(int alpha, vector<Node*>& nodes) {
    int n = nodes.size();
    int strengths[n];
    double xz[n];
    for (int i = 0; i < n; i++) {
        Node* node = nodes[i];
        node->vx += (xz[i] - node->x) * strengths[i] * alpha;
        strengths[i] = ForceX::strength(nodes, n);
    }
}

double ForceX::strength(vector<Node*>& nodes, int n) {
    return 0;
}



