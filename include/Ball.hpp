#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

struct Ball {
  sf::Vector2f pos;
  sf::Vector2f pos_old;
  sf::Vector2f acc;
  int radius;

  void draw(sf::RenderWindow &window);

  Ball(sf::Vector2f initPos, int initRadius);

  void updatePos(float dt);

  void accelerate(sf::Vector2f acceleration);

  void move(sf::Vector2f movement);
};

#endif // !BALL_H
