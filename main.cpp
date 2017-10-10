// LIFAP6 - Automne 2017 - R. Chaine

#include "element.h"
#include "liste.h"
#include "sliste.h"
#include <cstdio>

int main()
{

  Liste list;

  printf("Liste créée\n");

  list.ajoutEnTete(9);

  list.ajoutEnQueue(8);

  list.ajoutEnQueue(7);

  list.ajoutEnQueue(6);

  list.ajoutEnQueue(4);

  list.ajoutEnQueue(3);

  list.ajoutEnQueue(2);

  list.ajoutEnQueue(1);

  list.affichage();

  Sliste slist(list);

  printf("SListe créée\n");

  slist.inserer(5);

  slist.affichage();

  SCellule *cell = slist.recherche(15);

  if(cell != NULL)
  {

    printf("Elem trouvé");

  }
  else
  {

    printf("Elem non trouvé");

  }

  return 0;

}
