#include "../include/Solver.hpp"
#include "../include/Ball.hpp"
#include <SFML/System/Vector2.hpp>
#include <cmath>

void Solver::updateAll(float dt) {
  solveConstraint();
  for (Ball &ball : balls) {
    ball.updatePos(dt);
  }
}

void Solver::addBall() {
  Ball newBall = Ball{{300.0f, 300.0f}, {0.0f, 0.0f}, {0.0f, 100.0f}};

  balls.push_back(newBall);
}

void Solver::solveConstraint() {
  for (Ball &ball : balls) {
    float dist = distance(ball.pos, constraintPos);
    if (dist + 10 > constraintRadius) {
      // par triangle similaire

      sf::Vector2f move =
          (constraintPos - ball.pos) * ((dist - constraintRadius + 10) / dist);

      ball.pos += move;
    }
  }
}

float distance(sf::Vector2f a, sf::Vector2f b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float Solver::getConstraintRadius() { return constraintRadius; }
