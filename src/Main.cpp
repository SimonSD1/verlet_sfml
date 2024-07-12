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
  window.setFramerateLimit(120);
  sf::Clock dtClock;
  sf::Clock totalCLock;
  Solver solver;
  Renderer renderer{window, solver};
  float dt;
  int nb_balls = 0;

  solver.constraintRadius = 200.0f;
  solver.constraintPos = {800.0f / 2, 600.0f / 2};

  solver.addBall({400.0f, 300.0f}, 10);
  solver.addBall({401.0f, 300.0f}, 20);

  while (window.isOpen()) {
    sf::Event event;

    // ferme la fenetre si on clique sur la croix
    while (window.pollEvent(event)) {
      inputHandler(event, window);
    }

    window.clear();

    if (nb_balls < 30) {

      solver.addBall({401.0f, 300.0f}, nb_balls);
      nb_balls++;
    }

    dt = dtClock.restart().asSeconds();
    std::cout << dt << std::endl;
    solver.solve(dt);
    renderer.render();
    window.display();
  }

  return 0;
}
