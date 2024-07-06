#ifndef SOLVER_H
#define SOLVER_H

#include "Ball.hpp"

struct Solver {
public:
  std::vector<Ball> balls;

  void addBall(Ball &ball);
  void updateAll(float dt);
};
#endif // !SOLVER_H
