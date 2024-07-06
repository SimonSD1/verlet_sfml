#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
const sf::Vector2f gravity{0.0f, 9.81f};
struct Ball {
  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::Vector2f acc;

  void draw(sf::RenderWindow &window);

  void updatePos(float dt);
};

#endif // !BALL_H
