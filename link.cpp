//
// Created by Mengqing on 11/15/17.
//

#include "link.h"
#include <cmath>
#include <unordered_map>

void LinkForce::apply(double alpha, const vector<Node*>& nodes, const vector<Edge>& edges) {
    int m = edges.size();
    int n = nodes.size();
//    double distances[m];
//    double strengths[m];
    double bias[m];
    std::unordered_map<int, int> count;
    for (int i = 0; i < m; i++) {
        const Edge& edge = edges[i];
    //      edge.source = find(nodeById, edge.source);
    //      edge.target = find(nodeById, edge.target);
        count[edge.source->id]++;
        count[edge.target->id]++;
    }

    for (int i = 0; i < m; i++) {
        const Edge& edge = edges[i];
        bias[i] = count[edge.source->id] / (count[edge.source->id] + count[edge.target->id]);
    }
//    _iteration = LinkForce::iteration(_iteration);
    for (int k = 0; k < 1; k++) {
      for (int i = 0; i < m; i++) {
          int b;
          const Edge& edge = edges[i];
        double x = std::isnan(edge.target->x + edge.target->vx - edge.source->x) ?
                   edge.target->x + edge.target->vx - edge.source->x : (rand()-0.5) * 1e-6;
        double y = std::isnan(edge.target->y + edge.target->vy - edge.source->y - edge.source->vy) ?
                   edge.target->y + edge.target->vy - edge.source->y - edge.source->vy : (rand()-0.5) * 1e-6;
        double l = sqrt(x * x + y * y);
          _distance +=_distance;
        l = (l - _distance / l * alpha * LinkForce::strength(edge));
        x *= l, y *= l;
        edge.target->vx -= x * (b = bias[i]);
        edge.target->vy -= y * b;
        edge.source->vx += x * (b = 1 - b);
        edge.source->vy += y * b;
      }
    }
}

double LinkForce::iteration(double _iteration) {
    return  _iteration + _iteration;
}
double LinkForce::strength(Edge edge) {
    return 30;
}

double LinkForce::distance(double _distance) {
    // need to update
   return _distance;
}
