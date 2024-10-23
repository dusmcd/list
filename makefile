list.o: list.cpp list.hpp
	g++ $^ -c

main.o: main.cpp list.hpp
	g++ $< -c

test: main.o list.o
	g++ $^ -o test

clean:
	rm *.o test *.gch