#include "sliste.h"

#include <assert.h>

Sliste::Sliste()
{

	SCellule *celluleBidon = new SCellule();

	celluleBidon->info = INT_MIN;

	celluleBidon->nb_niv = 5;

	for(int i = 0; i < celluleBidon->nb_niv; i++)
	{

		celluleBidon->tetesSuivantes[i] = NULL;

	}

	this->teteListe = celluleBidon;

}

Sliste::Sliste(const Liste & l)
{

	if(l.ad == NULL)
	{

		SCellule *celluleBidon = new SCellule();

		celluleBidon->info = INT_MIN;

		celluleBidon->nb_niv = 5;

		for(int i = 0; i < celluleBidon->nb_niv; i++)
		{

			celluleBidon->tetesSuivantes[i] = NULL;

		}

		this->teteListe = celluleBidon;

	}
	else
	{

		Cellule *teteListeL = l.ad;

		SCellule *teteListe = new SCellule();

		teteListe->info = INT_MIN;

		teteListe->nb_niv = 5;

		for(int i = 0; i < teteListe->nb_niv; i++)
		{

			teteListe->tetesSuivantes[i] = NULL;

		}

		this->teteListe = teteListe;


		SCellule *cell = new SCellule();

		teteListe->tetesSuivantes[0] = cell;

		teteListe = teteListe->tetesSuivantes[0];

		teteListe->info = teteListeL->info;

		teteListe->nb_niv = 5;

		for(int i = 0; i < teteListe->nb_niv; i++)
		{

			teteListe->tetesSuivantes[i] = NULL;

		}

		while(teteListeL->suivant!=NULL)
		{

			teteListeL = teteListeL -> suivant;

			SCellule *cell = new SCellule();

			teteListe->tetesSuivantes[0] = cell;

			teteListe = teteListe->tetesSuivantes[0];

			teteListe->info = teteListeL->info;

			teteListe->nb_niv = 5;

			for(int i = 0; i < teteListe->nb_niv; i++)
			{

				teteListe->tetesSuivantes[i] = NULL;

			}

		}

	}

	//Generating skip list

	std::srand(std::time(0));

	int random;

	SCellule *localHead;

	SCellule *lastSavedForLevel;

	for (int i = 1; i < this->teteListe->nb_niv; i++)
	{

		localHead = this->teteListe;

		lastSavedForLevel = localHead;

		while(localHead->tetesSuivantes[i-1] != NULL)
		{

			localHead = localHead->tetesSuivantes[i-1];

			random = rand()%2;

			if(random)
			{

				lastSavedForLevel->tetesSuivantes[i] = localHead;

				lastSavedForLevel = lastSavedForLevel->tetesSuivantes[i];

			}

		}

		// printf("Niveau: %d\n", i);

	}

}

void Sliste::inserer(Elem e)
{

	if(recherche(e) != NULL)
	{

		return;

	}

	SCellule *localHead = this->teteListe;

	while(localHead->tetesSuivantes[0] != NULL && localHead->tetesSuivantes[0]->info > e)
	{

		localHead = localHead->tetesSuivantes[0];

	}

	SCellule *newCell = new SCellule();

	newCell->nb_niv = 5;

	for(int i = 0; i < newCell->nb_niv; i++)
	{

		newCell->tetesSuivantes[i] = NULL;

	}

	newCell->info = e;

	SCellule *nextCell = localHead->tetesSuivantes[0];

	localHead->tetesSuivantes[0] = newCell;

	newCell->tetesSuivantes[0] = nextCell;

}

SCellule * Sliste::recherche(Elem e)
{

	int i;

	SCellule *localHead = this->teteListe;

	if(localHead == NULL)
		return NULL;

	assert(localHead->tetesSuivantes != NULL);

	while(localHead->tetesSuivantes[0] != NULL)
	{

		i = 0;

		assert(i < localHead->nb_niv);

		while(localHead->tetesSuivantes[i] != NULL && i < localHead->nb_niv)
		{

			assert(localHead->tetesSuivantes[i]->info != INT_MIN);

			if(localHead->tetesSuivantes[i]->info == e)
			{

				return localHead->tetesSuivantes[i];

			}

			i++;

		}

		localHead = localHead->tetesSuivantes[0];

	}

	return NULL;

}

void Sliste::affichage()
{

	if(teteListe == NULL)
	{

		printf("\nLa liste est vide.\n");

		return;
	}

	SCellule *teteListe;

	teteListe = this->teteListe;

	while(teteListe->tetesSuivantes[0] != NULL)
	{

		if(teteListe->info == INT_MIN)
		{

			printf("\nELEMENT: -1; \tSUIVANTS: [");

		}
		else
		{

			printf("ELEMENT: %d; \tSUIVANTS: [", teteListe->info);

		}

		for (int i = 0; i < teteListe->nb_niv; i++)
		{

			if(teteListe->tetesSuivantes[i] == NULL)
			{

				printf("( )");

			}
			else
			{
				printf("(%d)", teteListe->tetesSuivantes[i]->info);

			}

		}

		printf("]\n");

		teteListe = teteListe->tetesSuivantes[0];

	}

	printf("ELEMENT: %d; \tSUIVANTS: [", teteListe->info);

	for (int i = 0; i < teteListe->nb_niv; i++)
	{

		if(teteListe->tetesSuivantes[i] == NULL)
		{

			printf("( )");

		}

	}

		printf("]\n");

	printf("----\n");

}

Sliste::~Sliste()
{

	

}