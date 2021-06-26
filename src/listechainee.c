#include "elementCollection.h"
#include "listechainee.h"
#include <stddef.h>
#include <stdlib.h>


LC_ListeChainee LC_listeChainee()
{
  return NULL;
}

int LC_estVide(LC_ListeChainee list)
{
  return (list==NULL);
}

void LC_ajouter(LC_ListeChainee* plist,void* source ,EC_FonctionCopierDansCollection copier)
{
  LC_ListeChainee pNoeud=(LC_ListeChainee)malloc(sizeof(LC_Noeud));
  void* donnee = copier(source);
  pNoeud->Element = donnee;
  pNoeud->listeSuivante=*plist;
  *plist=pNoeud;
}

void * LC_obtenirElement(LC_ListeChainee liste)
{
  return (liste->Element);
}


LC_ListeChainee  LC_obtenirListeSuivante (LC_ListeChainee liste)
{
  return (liste->listeSuivante);
}


void LC_fixerListeSuivante (LC_ListeChainee* pliste1,  LC_ListeChainee liste2) 
{
  (*pliste1)->listeSuivante=liste2;
}

void LC_fixerElement(LC_ListeChainee* pliste,void * source, EC_FonctionCopierDansCollection copier,EC_FonctionLibererDeCollection liberer)
{
  void* data =copier(source);
  liberer((*pliste)->Element);
  (*pliste)->Element=data;
}

void LC_supprimerTete(LC_ListeChainee* plist,EC_FonctionLibererDeCollection liberer)
{
  LC_ListeChainee temp;
  temp = *plist;
  *plist = LC_obtenirListeSuivante(*plist);
  liberer(temp->Element);
  free(temp);
}



void LC_supprimer(LC_ListeChainee* plist,EC_FonctionLibererDeCollection liberer)
{
  if (!LC_estVide(*plist)) {
    LC_supprimerTete(plist,liberer);
    LC_supprimer(plist,liberer);
    }
}

LC_ListeChainee LC_copier(LC_ListeChainee list,EC_FonctionCopierDansCollection copier)

{
  if (LC_estVide(list))
  {
    return LC_listeChainee();
  }
  else
  {  LC_ListeChainee temp;
    temp=LC_copier(LC_obtenirListeSuivante(list),copier);
    LC_ajouter(&temp,LC_obtenirElement(list),copier);
    return temp;
  }
}