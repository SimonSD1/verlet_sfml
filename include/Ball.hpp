#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

struct Ball {
  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::Vector2f acc;

  void draw(sf::RenderWindow &window);

  void updatePos(float dt);

  void accelerate(sf::Vector2f acceleration);

  void move(sf::Vector2f movement);
};

#endif // !BALL_H
