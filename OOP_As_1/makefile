stu: main.o student.o
	g++ -o stu main.o student.o
main.o: main.cpp student.h 
	g++ -c main.cpp
student.o: student.cpp student.h 
	g++ -c student.cpp

clean:
	rm student.o main.o