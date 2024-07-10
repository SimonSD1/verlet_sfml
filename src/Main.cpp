#include "../include/Main.hpp"
#include "../include/Ball.hpp"
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
  Ball ball;
  Solver solver;
  Renderer renderer{window, solver};

  solver.constraintRadius = 200.0f;
  solver.constraintPos = {800 / 2, 600 / 2};

  ball.acc = gravity;
  ball.vel = {0.0f, 0.0f};
  ball.pos = {250.0f, 300.0f};

  solver.addBall(ball);
  float time_total = 0.0f;

  while (window.isOpen()) {
    sf::Event event;

    // ferme la fenetre si on clique sur la croix
    while (window.pollEvent(event)) {
      // fonction de moi
      inputHandler(event, window);
    }

    window.clear();
    float new_total_time = clock.getElapsedTime().asSeconds();
    float elapsed_time = new_total_time - time_total;
    time_total = new_total_time;

    float dt = clock.restart().asSeconds();

    solver.updateAll(dt);
    renderer.render();
    window.display();
  }

  return 0;
}
