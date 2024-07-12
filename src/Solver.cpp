#include "../include/Solver.hpp"
#include "../include/Ball.hpp"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>

void Solver::solve(float dt) {
  for (int i = 0; i < 5; i++) {

    solveConstraint();
    solveCollisions();
    updatePos(dt / 5.0f);
  }
}

void Solver::updatePos(float dt) {
  for (Ball &ball : balls) {
    ball.updatePos(dt);
  }
}

void Solver::addBall(sf::Vector2f pos, int radius) {
  Ball newBall = Ball{pos, {0.0f, 0.0f}, {0.0f, 100.0f}, radius};

  balls.push_back(newBall);
}

void Solver::solveConstraint() {
  for (Ball &ball : balls) {
    float dist = distance(ball.pos, constraintPos);
    if (dist + ball.radius > constraintRadius) {
      // par triangle similaire

      sf::Vector2f move = (constraintPos - ball.pos) *
                          ((dist - constraintRadius + ball.radius) / dist);

      ball.pos += move / 2.0f;
    }
  }
}

void Solver::solveCollisions() {

  for (Ball &ball : balls) {
    for (Ball &second_ball : balls) {
      if (&ball != &second_ball) {
        float dist = distance(ball.pos, second_ball.pos);
        if (dist < ball.radius + second_ball.radius) {
          sf::Vector2f move =
              (ball.pos - second_ball.pos) *
              ((dist - ball.radius - second_ball.radius) / dist);

          second_ball.pos += move / 2.0f;
          ball.pos -= move / 2.0f;
        }
      }
    }
  }
}

float distance(sf::Vector2f a, sf::Vector2f b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float Solver::getConstraintRadius() { return constraintRadius; }
