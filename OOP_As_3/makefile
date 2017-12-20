adventure: main.o adventure.o
	g++ -o adventure main.o adventure.o
main.o: main.cpp adventure.h 
	g++ -c main.cpp
adventure.o: adventure.cpp adventure.h 
	g++ -c adventure.cpp

clean:
	rm adventure.o main.o