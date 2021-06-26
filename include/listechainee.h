#ifndef __LC__
#define __LC__

#include "elementCollection.h"

typedef struct LC_Noeud* LC_ListeChainee;

typedef struct LC_Noeud
{
  void* Element;
  LC_ListeChainee listeSuivante;
} LC_Noeud;


LC_ListeChainee  LC_listeChainee () ;
int LC_estVide(LC_ListeChainee);
void LC_ajouter(LC_ListeChainee*,void*,EC_FonctionCopierDansCollection);
void * LC_obtenirElement(LC_ListeChainee);
LC_ListeChainee  LC_obtenirListeSuivante (LC_ListeChainee) ;
void LC_fixerListeSuivante (LC_ListeChainee*,  LC_ListeChainee) ;
void LC_fixerElement(LC_ListeChainee*,void* ,EC_FonctionCopierDansCollection,EC_FonctionLibererDeCollection);
void LC_supprimerTete(LC_ListeChainee*,EC_FonctionLibererDeCollection);
void LC_supprimer(LC_ListeChainee*,EC_FonctionLibererDeCollection);
LC_ListeChainee LC_copier(LC_ListeChainee,EC_FonctionCopierDansCollection);

#endif
