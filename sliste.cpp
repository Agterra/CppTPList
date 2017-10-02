#include "sliste.h"



Sliste::Sliste()
{

	this->ad = NULL;

}

Sliste::Sliste(const Liste & l)
{

	SCellule *localHead = new SCellule();

	localHead->info = -999999;

	Cellule *passedHead = l.ad;



}