build/app: bin/main.o bin/Ball.o bin/solver.o
	g++ bin/main.o bin/Ball.o bin/solver.o -o build/app -lsfml-graphics -lsfml-window -lsfml-system


bin/main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o

bin/Ball.o: src/Ball.cpp
	g++ -c src/Ball.cpp -o bin/Ball.o

bin/renderer.o: src/renderer.cpp
	g++ -c src/renderer.cpp -o bin/renderer.o

bin/solver.o: src/solver.cpp
	g++ -c src/solver.cpp -o bin/solver.o
