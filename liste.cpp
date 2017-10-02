#include "liste.h"

#include <cstdio>

Liste::Liste()
{

    this->ad = NULL;

}

Liste::Liste(const Liste & l)
{

    Cellule *localHead = new Cellule();

    Cellule *passedHead = l.ad;

    localHead->info = passedHead->info;

    this->ad = localHead;

    while(passedHead->suivant != NULL)
    {

        passedHead = passedHead->suivant;

        Cellule *newCellule = new Cellule();

        localHead->suivant = newCellule;

        localHead = localHead->suivant;

        localHead->info = passedHead->info;

    }

}

Liste::~Liste()
{

    vide();

}

Liste & Liste::operator = (const Liste & l)
{

    if(l.ad == NULL)
    {

        vide();

        return *this;

    }

    Cellule *localHead = new Cellule();

    Cellule *passedHead = l.ad;

    localHead->info = passedHead->info;

    this->ad = localHead;

    while(passedHead->suivant != NULL)
    {

        passedHead = passedHead->suivant;

        Cellule *newCellule = new Cellule();

        localHead->suivant = newCellule;

        localHead = localHead->suivant;

        localHead->info = passedHead->info;

    }
        
    return *this;

}

bool Liste::testVide() const
{

    if(this->ad == NULL)
        return true;

    return false;

}

Elem Liste::premierElement() const
{

    return this->ad->info;

}

Cellule * Liste::premiereCellule() const
{

    return this->ad;

}

Cellule * Liste::celluleSuivante(const Cellule *c) const
{

    if(c == NULL)
        return NULL;

    Cellule *localHead = this->ad;

    while(localHead->suivant != NULL)
    {

        if(c->info == localHead->info)
            return localHead->suivant;

        localHead = localHead->suivant;

    }

    return NULL;

}

Elem Liste::elementCellule(const Cellule *c) const
{

    return c->info;

}

void Liste::affichage() const
{

    Cellule *localHead = this->ad;

    if(this->ad == NULL)
    {

        printf("La liste est vide\n");

        return;

    }

    printf("[");

    while(localHead->suivant != NULL)
    {

        printf("%d; ", localHead->info);

        localHead = localHead->suivant;

    } 

    printf("%d]\n", localHead->info);

}
    
void Liste::ajoutEnTete(const Elem & e)
{

    Cellule *newCellule = new Cellule();

    newCellule->info = e;

    newCellule->suivant = this->ad;

    this->ad = newCellule;

}
    
void Liste::suppressionEnTete()
{

    Cellule *poubelle = this->ad;

    Cellule *localHead = this->ad;

    localHead = localHead->suivant;

    delete(poubelle);

    this->ad = localHead;

}
     
void Liste::vide()
{


    if(this->ad == NULL)
        return;

    Cellule *localHead = this->ad;

    while(localHead->suivant != NULL)
    {

        Cellule *poubelle = localHead;

        localHead = localHead->suivant;

        delete(poubelle);

    }

    this->ad = NULL;

}
     
void Liste::ajoutEnQueue(const Elem & e)
{

    Cellule *localHead = this->ad;

    while(localHead->suivant != NULL)
    {

        localHead = localHead->suivant;

    }

    Cellule *lastCell = new Cellule();

    lastCell->info = e;

    localHead->suivant = lastCell;

}

Cellule * Liste::rechercheElement(const Elem & e) const
{

    Cellule *localHead = this->ad;

    while(localHead->info != e && localHead != NULL)
    {

        localHead = localHead->suivant;

    } 

    return localHead;

}

// void insereElementApresCellule(const Elem & e,Cellule *c)
// {



// }


// void modifieInfoCellule(const Elem & e,Cellule *c)
// {



// }
    
// void ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *c)
// {



// }

// void affichageDepuisCellule(const Cellule * c) const
// {



// }







