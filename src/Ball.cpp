#include "../include/Ball.hpp"
#include <SFML/System/Vector2.hpp>

void Ball::draw(sf::RenderWindow &window) {
  sf::CircleShape circle(10);
  circle.setPosition(pos.x, pos.y);
  window.draw(circle); // Draw the circle to the window
}

void Ball::updatePos(float dt) {
  sf::Vector2f new_pos = pos + vel * dt + acc * (dt * dt * 0.5f);
  sf::Vector2f new_acc = acc + gravity;
  sf::Vector2f new_vel = vel + (acc + new_acc) * (dt * 0.5f);

  pos = new_pos;
  acc = new_acc;
  vel = new_vel;
}
