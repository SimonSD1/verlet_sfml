#ifndef SOLVER_H
#define SOLVER_H

#include "Ball.hpp"
#include <SFML/System/Vector2.hpp>

struct Solver {
public:
  sf::Vector2f constraintPos;
  float constraintRadius;
  std::vector<Ball> balls;

  void addBall();
  void updateAll(float dt);

  void solveConstraint();
  float getConstraintRadius();
};

float distance(sf::Vector2f a, sf::Vector2f b);
#endif // !SOLVER_H
