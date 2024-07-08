#include "../include/Solver.hpp"
void Solver::updateAll(float dt) {
  for (Ball &ball : balls) {
    ball.updatePos(dt);
  }
}

void Solver::addBall(Ball ball) { balls.push_back(ball); }
