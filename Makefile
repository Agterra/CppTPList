prog : main.o liste.o element.o
	g++ main.o liste.o element.o -o

main.o : main.cpp liste.h element.h
	g++ -o -Wall main.cpp

liste.o : liste.cpp liste.h
	g++ -o -Wall liste.cpp

element.o : element.cpp element.h
	g++ -o -Wall element.cpp