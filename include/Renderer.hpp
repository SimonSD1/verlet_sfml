#ifndef RENDERER_H
#define RENDERER_H
#include "solver.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
struct Renderer {
public:
  sf::RenderWindow &target;
  Solver &solver;

  void render();
};

#endif // !RENDERER_H
