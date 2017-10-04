// LIFAP6 - Automne 2017 - R. Chaine

#include "element.h"
#include "liste.h"
#include "sliste.h"
#include <cstdio>

int main()
{

  Liste list;

  printf("Liste créée\n");

  list.ajoutEnTete(10);

  list.ajoutEnQueue(9);

  list.ajoutEnQueue(8);

  list.ajoutEnQueue(7);

  list.ajoutEnQueue(6);

  list.ajoutEnQueue(5);

  list.ajoutEnQueue(4);

  list.ajoutEnQueue(3);

  list.ajoutEnQueue(2);

  list.ajoutEnQueue(1);

  list.affichage();

  Sliste slist(list);

  printf("SListe créée\n");

  return 0;

}
