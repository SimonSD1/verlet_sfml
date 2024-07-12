#ifndef SOLVER_H
#define SOLVER_H

#include "Ball.hpp"
#include <SFML/System/Vector2.hpp>

struct Solver {
public:
  sf::Vector2f constraintPos;
  float constraintRadius;
  std::vector<Ball> balls;

  void addBall(sf::Vector2f pos, int radius);
  void solve(float dt);

  void solveConstraint();
  void solveCollisions();
  void updatePos(float dt);
  float getConstraintRadius();
};

float distance(sf::Vector2f a, sf::Vector2f b);
#endif // !SOLVER_H
