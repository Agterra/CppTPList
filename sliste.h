#ifndef _SLISTE
#define _SLISTE

#include <cstdio>

#include "element.h"

#include "liste.h"

class Sliste;

class SCellule
{

    friend class Sliste;

    private:
    	Elem info;
    	SCellule tab[5];

}

class Sliste
{

SCellule *ad;

public:

	Sliste();

	Sliste(const Liste & l);

	~Sliste();
	
};