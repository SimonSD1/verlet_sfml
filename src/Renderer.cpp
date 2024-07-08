#include "../include/Renderer.hpp"

void Renderer::render() {
  for (Ball &ball : solver.balls) {
    ball.draw(target);
  }
}
