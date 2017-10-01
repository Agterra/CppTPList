/*
   Liste();
    Liste(const Liste & l);
     ~Liste();
    Liste & operator = (const Liste & l);
    bool testVide() const;
     Elem premierElement() const;
    
    Cellule * premiereCellule() const;
    Cellule * celluleSuivante(const Cellule *c) const;
    
    Elem elementCellule(const Cellule * c) const;
     
    void affichage() const;
      
    void ajoutEnTete(const Elem & e);
    
    void suppressionEnTete();
     
    void vide();
     
    void ajoutEnQueue(const Elem & e);
    Cellule * rechercheElement(const Elem & e) const;
       void insereElementApresCellule(const Elem & e,Cellule *c);
    
    void modifieInfoCellule(const Elem & e,Cellule *c);
         void ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *c);
    void affichageDepuisCellule(const Cellule * c) const;*/

#include "liste.h"

Liste::Liste()
{

    this->ad = nullptr;

}