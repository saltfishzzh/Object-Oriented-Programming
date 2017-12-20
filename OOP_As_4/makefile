all: pdadd pdlist pdremove pdshow

pdadd: pdadd.o diary.o
	g++ -o pdadd pdadd.o diary.o
pdadd.o: pdadd.cpp diary.h 
	g++ -c pdadd.cpp
diary.o: diary.cpp diary.h 
	g++ -c diary.cpp

pdlist: pdlist.o diary.o
	g++ -o pdlist pdlist.o diary.o
pdlist.o: pdlist.cpp diary.h 
	g++ -c pdlist.cpp

pdshow: pdshow.o diary.o
	g++ -o pdshow pdshow.o diary.o
pdshow.o: pdshow.cpp diary.h 
	g++ -c pdshow.cpp

pdremove: pdremove.o diary.o
	g++ -o pdremove pdremove.o diary.o
pdremove.o: pdremove.cpp diary.h 
	g++ -c pdremove.cpp
clean:
	rm pdadd.o pdlist.o pdshow.o pdremove.o diary.o