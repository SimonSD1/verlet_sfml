build/app: bin/Main.o bin/Ball.o bin/Solver.o bin/Renderer.o
	g++ bin/Main.o bin/Ball.o bin/Solver.o bin/Renderer.o -o build/app -lsfml-graphics -lsfml-window -lsfml-system

bin/Renderer.o: src/Renderer.cpp
	g++ -c src/Renderer.cpp -o bin/Renderer.o

bin/Main.o: src/Main.cpp
	g++ -c src/Main.cpp -o bin/Main.o

bin/Ball.o: src/Ball.cpp
	g++ -c src/Ball.cpp -o bin/Ball.o

bin/Solver.o: src/Solver.cpp
	g++ -c src/Solver.cpp -o bin/Solver.o
