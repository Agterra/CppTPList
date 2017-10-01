prog : main.o liste.o element.o
	g++ main.o liste.o element.o

main.o : main.cpp liste.h element.h
	g++ -c -Wall main.cpp

liste.o : liste.cpp 
	g++ -c -Wall liste.cpp

element.o : element.cpp
	g++ -c -Wall element.cpp