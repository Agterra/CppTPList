#ifndef _SLISTE
#define _SLISTE

#include <cstdio>

#include <climits>

#include <cstdlib>

#include <ctime>

#include <vector>

#include <iostream>

#include "element.h"

#include "liste.h"

class Sliste;

class SCellule
{

    friend class Sliste;

    private:

    	Elem info;
    	
    	SCellule *tetesSuivantes[5];
    	
    	int nb_niv;

};

class Sliste
{

public:

	Sliste();

	Sliste(const Liste & l);

	~Sliste();

	void inserer(Elem e);

	SCellule * recherche(Elem e);

	void affichage();
	
private:

	SCellule *teteListe;

};

#endif