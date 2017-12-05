//
// Created by Mengqing on 11/21/17.
//

#include "manybody.h"
#include "Quadtree.h"

using namespace std;
void Charge::force(vector<Node*>& nodes, double alpha, vector<Quadtree*>& tree) {
    int n = nodes.size();
    tree = Charge::quadtree(nodes, x, y).visitAfter(accumulate);
    for (int i = 0; i < n; ++i) {
        Node* node = nodes[i];
        tree.visit(apply);
    }
}

Quadtree Charge::quadtree(vector<Node*>& nodes, int x, int y) {

}
void Charge::apply(Node* node, double x1, double x2, double alpha) {
    double theta2 = 0.81;
    double distanceMin2 = 1;
    double distanceMax2 = std::numeric_limits<double>::infinity();
    double x = quad.x - node->x;
    double y = quad.y - node->y;
    double w = x2 - x1;
    double l = x * x + y * y;

    // Apply the Barnes-Hut approximation if possible.
    // Limit forces for very close nodes; randomize direction if coincident.
    if (w * w / theta2 < l) {
        if (l < distanceMax2) {
            if (x == 0) {
                x = (random() - 0.5) * 1e-6;
                l += x * x;
            }
            if (y == 0) {
                y = (random() - 0.5) * 1e-6;
                l += y * y;
            }
            if (l < distanceMin2) {
                l = sqrt(distanceMin2 * l);
            }
            node->vx += x * quad.value * alpha / l;
            node->vy += y * quad.value * alpha / l;
        }
        return true;
    }

        // Otherwise, process points directly.
    else if (quad.length || l >= distanceMax2) return;

    // Limit forces for very close nodes; randomize direction if coincident.
    if (quad.data != node || quad.next) {
        if (x == 0) {
            x = (random() - 0.5) * 1e-6;
            l += x * x;
        }

        if (y == 0) {
            y = (random() - 0.5) * 1e-6;
            l += y * y;
        }
        if (l < distanceMin2) {
            l = sqrt(distanceMin2 * l);
        }
    }

    do if (quad.data !== node) {
            w = strengths[quad.data.index] * alpha / l;
            node->vx += x * w;
            node->vy += y * w;
        } while (quad = quad.next);
}
void Charge::initialize(vector<Node*>& nodes) {
    int n = nodes.size();
    int strengths[n];
    for (int i = 0; i < n; i++) {
        Node* node = nodes[i];
        strengths[i] = Charge::strength(nodes, n);
    }
}

void Charge::accumulate(vector<quad> quad) {
    int strength = 0, q, c, weight = 0, x, y, i;
    // For internal nodes, accumulate forces from child quadrants.
    if (quad.size()) {
        for (int i = 0; i < 4; ++i) {
            if ((q = quad[i]) && (c = abs(q.value))) {
                strength += q.value, weight += c, x += c * q.x, y += c * q.y;
            }
        }
        quad.x = x / weight;
        quad.y = y / weight;
    } else {// For leaf nodes, accumulate forces from coincident quadrants.
        q = quad;
        q.x = q.data.x;
        q.y = q.data.y;
        do strength += strengths[q.data.index];
        while (q = q.next);
    }

    quad.value = strength;
}

double Charge::strength(vector<Node*>& nodes, int n) {
    return -30;
}