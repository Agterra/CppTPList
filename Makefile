prog : main.o liste.o element.o sliste.o
	g++ main.o liste.o element.o sliste.o

main.o : main.cpp liste.h element.h sliste.h
	g++ -c -Wall main.cpp

liste.o : liste.cpp 
	g++ -c -Wall liste.cpp

element.o : element.cpp
	g++ -c -Wall element.cpp

sliste.o : sliste.cpp
	g++ -c -Wall sliste.cpp