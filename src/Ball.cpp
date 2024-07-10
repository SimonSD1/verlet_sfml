#include "../include/Ball.hpp"
#include <SFML/System/Vector2.hpp>

void Ball::draw(sf::RenderWindow &window) {
  sf::CircleShape circle(10);
  circle.setOrigin(10, 10);
  circle.setPosition(pos.x, pos.y);
  window.draw(circle); // Draw the circle to the window
}

void Ball::updatePos(float dt) {
  sf::Vector2f new_pos = pos + vel * dt + acc * (dt * dt * 0.5f);
  sf::Vector2f new_vel = vel + (acc + acc) * (dt * 0.5f);

  pos = new_pos;
  vel = new_vel;
}

void Ball::accelerate(sf::Vector2f acceleration) { acc += acceleration; }

void Ball::move(sf::Vector2f movement) { pos += movement; }
