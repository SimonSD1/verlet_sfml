#include "../include/solver.hpp"
void Solver::updateAll(float dt) {
  for (Ball &ball : balls) {
    // std::cout << ball.pos.y << std::endl;
    ball.updatePos(dt);
    //    std::cout << ball.pos.y << std::endl;
  }
}

void Solver::addBall(Ball &ball) { balls.push_back(ball); }
