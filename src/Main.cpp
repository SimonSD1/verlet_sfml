#include "../include/Main.hpp"
#include "../include/Renderer.hpp"
#include "../include/Solver.hpp"

// gestion des events et input
void inputHandler(sf::Event event, sf::RenderWindow &window) {
  if (event.type == sf::Event::Closed) {
    window.close();
  }
}

int main(int argc, char *argv[]) {

  sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT),
                          "mon titre"); // Use sf::RenderWindow for rendering
  sf::Clock clock;
  Solver solver;
  Renderer renderer{window, solver};
  float dt;

  solver.constraintRadius = 200.0f;
  solver.constraintPos = {800 / 2, 600 / 2};

  solver.addBall();

  while (window.isOpen()) {
    sf::Event event;

    // ferme la fenetre si on clique sur la croix
    while (window.pollEvent(event)) {
      inputHandler(event, window);
    }

    window.clear();

    dt = clock.restart().asSeconds();

    solver.updateAll(dt);
    renderer.render();
    window.display();
  }

  return 0;
}
