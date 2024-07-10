#include "../include/Renderer.hpp"

void Renderer::render() {

  sf::CircleShape constraint_background{solver.constraintRadius};
  constraint_background.setFillColor(sf::Color::Green);
  constraint_background.setPosition(solver.constraintPos);
  constraint_background.setOrigin(solver.getConstraintRadius(),
                                  solver.getConstraintRadius());

  target.draw(constraint_background);

  for (Ball &ball : solver.balls) {
    ball.draw(target);
  }
}
