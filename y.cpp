//
// Created by Mengqing on 11/15/17.
//


#include "y.h"

void ForceY::apply(int alpha, vector<Node> nodes) {
    int n = nodes.size();
    int strengths[n];
    double yz[n];
    for (int i = 0; i < n; i++) {
        Node node = nodes[i];
        node.vy += (yz[i] - node.y) * strengths[i] * alpha;
        strengths[i] = ForceY::strength(nodes, n);
    }
}
double ForceY::strength(vector<Node> nodes, int n) {
    return 0;
}

