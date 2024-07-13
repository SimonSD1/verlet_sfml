#ifndef RENDERER_H
#define RENDERER_H
#include "Solver.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <sstream>

struct Renderer {
public:
  sf::RenderWindow &target;
  Solver &solver;
  sf::Font font;

  sf::Text textFrameTime;
  std::stringstream fpsText;

  Renderer(sf::RenderWindow &target, Solver &solver,
           const std::string &fontPath);

  void render(float frameTime);
};

#endif // !RENDERER_H
