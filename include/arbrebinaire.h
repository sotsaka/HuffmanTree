#ifndef ___AB___
#define ___AB___

#include "elementCollection.h"

typedef struct AB_Noeud* AB_ArbreBinaire;

typedef struct AB_Noeud {
  void* lElement;
  AB_ArbreBinaire filsGauche;
  AB_ArbreBinaire filsDroit;
}AB_Noeud;

AB_ArbreBinaire AB_arbreBinaire();
int AB_estVide(AB_ArbreBinaire arbre);
AB_ArbreBinaire AB_ajouterRacine(AB_ArbreBinaire a1, AB_ArbreBinaire a2, void* source,  EC_FonctionCopierDansCollection copier, EC_FonctionLibererDeCollection coller);
void* AB_obtenirElement(AB_ArbreBinaire arbre);
AB_ArbreBinaire AB_obtenirFilsGauche(AB_ArbreBinaire arbre);
AB_ArbreBinaire AB_obtenirFilsDroit(AB_ArbreBinaire arbre);
void AB_fixerFilsGauche(AB_ArbreBinaire arbre, AB_ArbreBinaire fg);
void AB_fixerFilsDroit(AB_ArbreBinaire arbre, AB_ArbreBinaire fg);
void AB_fixerElement(AB_ArbreBinaire arbre, void* source, EC_FonctionCopierDansCollection copier, EC_FonctionLibererDeCollection coller);
void AB_supprimerArbre(AB_ArbreBinaire, EC_FonctionLibererDeCollection);


#endif
