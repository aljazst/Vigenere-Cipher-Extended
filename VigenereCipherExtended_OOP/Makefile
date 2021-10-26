# very basic makefile

output: main.o VigenereCipherExtended.o 
	g++ main.o VigenereCipherExtended.o -o cipher


VigenereCipherExtended.o: VigenereCipherExtended.cpp VigenereCipherExtended.hpp
	g++ -c VigenereCipherExtended.cpp -o VigenereCipherExtended.o

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o cipher