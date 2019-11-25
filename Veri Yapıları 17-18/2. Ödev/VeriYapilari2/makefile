hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Yonetim.o -c ./src/Yonetim.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Stack.o ./lib/Node.o ./lib/Yonetim.o ./src/Test.cpp

	
calistir:
	./bin/Test