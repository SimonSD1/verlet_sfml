#include "../include/Ball.hpp"
#include <SFML/System/Vector2.hpp>

void Ball::draw(sf::RenderWindow &window) {
  sf::CircleShape circle(radius);
  circle.setOrigin(radius, radius);
  circle.setPosition(pos.x, pos.y);
  window.draw(circle); // Draw the circle to the window
}

void Ball::updatePos(float dt) {
  sf::Vector2f vel = pos - pos_old;
  pos_old = pos;
  pos = pos + vel + acc * (dt * dt);
}

Ball::Ball(sf::Vector2f initPos, int initRadius)
    : pos(initPos), pos_old(initPos), acc(0, 700.0f), radius(initRadius) {}

void Ball::accelerate(sf::Vector2f acceleration) { acc += acceleration; }

void Ball::move(sf::Vector2f movement) { pos += movement; }
