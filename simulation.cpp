//
// Created by Mengqing on 11/14/17.
//

#include "simulation.h"
#include "link.h"
#include "center.h"

void Simulation::simulation(const vector<Node*>& nodes, const vector<Edge>& edges) {
    int n = nodes.size();
//    ForceX::apply(_alpha, nodes);
//    ForceY::apply(_alpha, nodes);
    initializeNodes(nodes);
    step(nodes,edges);
}

void Simulation::step(const vector<Node*>& nodes, const vector<Edge>& edges) {
    _alpha = alpha(_alpha);
    _alphaMin = alphaMin(_alphaMin);
    tick(nodes, edges);
    while (_alpha > _alphaMin) {
       Simulation::simulation(nodes, edges);
    }
}
void Simulation::tick(const vector<Node*>& nodes, const vector<Edge>& edges) {
    int n = nodes.size();
    _alphaTarget = alphaTarget(_alphaTarget);
    _alphaDecay = alphaDecay(_alphaDecay);
    _alpha += (_alphaTarget - _alpha) * _alphaDecay;
    LinkForce link;
    link.apply(_alpha, nodes, edges);
    CenterForce::apply(400, 400, nodes);
    for (int i = 0; i < n; i++) {
        _velocityDecay = velocityDecay(_velocityDecay);
        Node* node = nodes[i];
        if (std::isnan(node->fx)) {
            node->vx = node->vx * _velocityDecay;
            node->x =node->x + node->vx;
        } else {
            node->x = node->fx;
            node->vx = 0;
        }
        if (std::isnan(node->fy)) {
            node->vy = node->vy * _velocityDecay;
            node->y =node->y + node->vy;
        } else {
            node->y = node->fy;
            node->vy = 0;
        }
    }
}

void Simulation::initializeNodes(const vector<Node*>& nodes) {
    int n = nodes.size();
    double initialRadius = 10;
    double initialAngle = M_PI * (3 - sqrt(5));
  for (int i = 0; i < n; i++) {
      Node* node = nodes[i];
      node->id = i;
      if (!std::isnan(node->x) || !std::isnan(node->y)) {
          int radius = initialRadius * sqrt(i), angle = i * initialAngle;
          node->x = radius * cos(angle);
          node->y = radius * sin(angle);
      }
      if (!std::isnan(node->vx) || !std::isnan(node->vy)) {
        node->vx = node->vy = 0;
      }
  }
}


double Simulation::alpha(double _alpha) {
    _alpha += _alpha;
    return _alpha;
}
double Simulation::alphaMin(double _alphaMin) {
    return _alphaMin + _alphaMin;
}

double Simulation::alphaDecay(double _alphaDecay) {
    return _alphaDecay + _alphaDecay;
}

double Simulation::alphaTarget(double _alphaTarget) {
    return _alphaTarget + _alphaTarget;
}

double Simulation::velocityDecay(double _velocityDecay) {
    return 1 - _velocityDecay;
}




