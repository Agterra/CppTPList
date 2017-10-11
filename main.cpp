// LIFAP6 - Automne 2017 - R. Chaine

#include "element.h"
#include "liste.h"
#include "sliste.h"
#include <cstdio>

#include <stdio.h>

#include <iostream>

#include <fstream>

#include <chrono>

#define NB_SKIP_LIST 100

int main()
{

  printf("\n\n\n### PROGRAM STARTS ###\n");

  Liste list;

  printf("\nListe créée\n");

  list.ajoutEnTete(9);

  list.ajoutEnQueue(8);

  list.ajoutEnQueue(7);

  list.ajoutEnQueue(6);

  list.ajoutEnQueue(4);

  list.ajoutEnQueue(3);

  list.ajoutEnQueue(2);

  list.ajoutEnQueue(1);

  Sliste slist(list);

  printf("\nSListe créée\n\n----");

  slist.inserer(5);

  slist.affichage();

  // SCellule *cell = slist.recherche(15);



  // if(cell != NULL)
  // {

  //   printf("Elem trouvé");

  // }
  // else
  // {

  //   printf("Elem non trouvé");

  // }
  
  std::srand(std::time(NULL));
  
  int random;

  Sliste tab[NB_SKIP_LIST];
  
  for(int i = 0; i < NB_SKIP_LIST; i++)
  {
  	
	  Sliste slist;

    tab[i] = slist;
	
  }

  std::vector<std::chrono::time_point<std::chrono::system_clock> > times;

  std::chrono::time_point<std::chrono::system_clock> start, end;

  start = std::chrono::system_clock::now();

  for(int j = 0; j < 10000; j++)
  {

    for(int i = 0; i < NB_SKIP_LIST; i++)
    {

      random = rand()%NB_SKIP_LIST;

      Sliste sliste = tab[i];

      if(sliste.recherche(random) == NULL)
      {

        sliste.inserer(random);

      }

    }

    if(j%1000 == 0)
    {

      end = std::chrono::system_clock::now();

      times.push_back(end);

    }

  }

  printf("\n### TIMES (in ms): ###\n\nNumber of skip lists: %d\nNumber of iterations: 10000\nInterval: each 1000 iterations\n\n", NB_SKIP_LIST);

  for(int i = 1000; i < 10000; i+=1000)
  {

    printf("%d\t", i);

  }

  printf("\n");

  char data[] = "# \"NB ELEMENTS\" \"TIME\" ";

  std::ofstream outfile;

  outfile.open("perfs.txt");

  outfile << data << std::endl;

  for (int i = 1; i < times.size(); i++)
  {

    start = times[i-1];

    end = times[i];

    int elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    outfile << i*1000 << " " << elapsed_microseconds/1000 << std::endl;

    printf("[%d]\t", elapsed_microseconds/1000);

  }

  printf("\n\n### PROGRAM END ###\n\n\n");

  return 0;

}
