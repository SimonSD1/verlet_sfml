#include "../include/Renderer.hpp"
#include <SFML/Graphics/Text.hpp>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>

void Renderer::render(float frameTime) {

  sf::CircleShape constraint_background{solver.constraintRadius};
  constraint_background.setFillColor(sf::Color::Blue);
  constraint_background.setPosition(solver.constraintPos);
  constraint_background.setOrigin(solver.getConstraintRadius(),
                                  solver.getConstraintRadius());

  target.draw(constraint_background);

  for (Ball &ball : solver.balls) {
    ball.draw(target);
  }

  fpsText.str("");
  fpsText << std::fixed << std::setprecision(1) << (1.0f / frameTime) << " fps";
  std::cout << fpsText.str() << std::endl;
  textFrameTime.setString(fpsText.str());

  target.draw(textFrameTime);
}

Renderer::Renderer(sf::RenderWindow &target, Solver &solver,
                   const std::string &fontPath)
    : target(target), solver(solver) {
  if (!font.loadFromFile(fontPath)) {
    throw std::runtime_error("erreur font");
  }
  textFrameTime.setFont(font);
  textFrameTime.setFillColor(sf::Color::Green);
  textFrameTime.setPosition({0.0f, 0.0f});
}
