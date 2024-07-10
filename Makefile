build/app: bin/Main.o bin/Ball.o bin/Solver.o bin/Renderer.o
	g++ bin/Main.o bin/Ball.o bin/Solver.o bin/Renderer.o -o build/app -lsfml-graphics -lsfml-window -lsfml-system

bin/Renderer.o: src/Renderer.cpp include/Renderer.hpp
	g++ -c src/Renderer.cpp -o bin/Renderer.o

bin/Main.o: src/Main.cpp include/Main.hpp
	g++ -c src/Main.cpp -o bin/Main.o

bin/Ball.o: src/Ball.cpp include/Ball.hpp
	g++ -c src/Ball.cpp -o bin/Ball.o

bin/Solver.o: src/Solver.cpp include/Solver.hpp
	g++ -c src/Solver.cpp -o bin/Solver.o


bin/Main.o: include/Ball.hpp include/Solver.hpp include/Renderer.hpp
bin/Ball.o: include/Ball.hpp
bin/Solver.o: include/Solver.hpp
bin/Renderer.o: include/Renderer.hpp
