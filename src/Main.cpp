#include "../include/Main.hpp"
#include "../include/Renderer.hpp"
#include "../include/Solver.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

// gestion des events et input
void inputHandler(sf::Event event, sf::RenderWindow &window) {
  if (event.type == sf::Event::Closed) {
    window.close();
  }
}

int main(int argc, char *argv[]) {

  sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT),
                          "verlet"); // Use sf::RenderWindow for rendering
  window.setFramerateLimit(144);

  sf::Clock dtClock;
  sf::Clock spawnClock;

  Solver solver{{800.0f / 2, 600.0f / 2}, 200.0f};
  Renderer renderer{window, solver};

  float dt;
  int nb_balls = 0;

  while (window.isOpen()) {
    sf::Event event;

    // ferme la fenetre si on clique sur la croix
    while (window.pollEvent(event)) {
      inputHandler(event, window);
    }

    window.clear();

    if (nb_balls < 2000 && spawnClock.getElapsedTime().asSeconds() > 0.25) {
      solver.addBall({300.0f, 250.0f}, 6);
      nb_balls++;
      std::cout << nb_balls << std::endl;
      spawnClock.restart();
    }

    dt = dtClock.restart().asSeconds();
    solver.solve(dt);
    renderer.render();
    window.display();
  }

  return 0;
}
