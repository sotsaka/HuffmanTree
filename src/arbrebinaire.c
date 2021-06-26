#include "arbrebinaire.h"
#include "elementCollection.h"
#include <stddef.h>
#include <stdlib.h>

AB_ArbreBinaire AB_arbreBinaire()
{
	AB_ArbreBinaire arbre =(AB_Noeud*)malloc(sizeof(AB_Noeud));
	arbre->lElement = NULL;
	arbre->filsGauche = NULL;
	arbre->filsDroit = NULL;
	
  return arbre;
}


int AB_estVide(AB_ArbreBinaire arbre)
{
  return (arbre == NULL);
}


void* AB_obtenirElement(AB_ArbreBinaire arbre)
{
  return (arbre->lElement);
}

AB_ArbreBinaire AB_obtenirFilsGauche(AB_ArbreBinaire arbre)
{
  return (arbre->filsGauche);
}


AB_ArbreBinaire AB_obtenirFilsDroit(AB_ArbreBinaire arbre)
{
  return (arbre->filsDroit);
}


void AB_fixerFilsGauche(AB_ArbreBinaire arbre, AB_ArbreBinaire fg)
{
 arbre->filsGauche=fg;
}


void AB_fixerFilsDroit(AB_ArbreBinaire arbre, AB_ArbreBinaire fd)
{
 arbre->filsDroit=fd;
}


void AB_fixerElement(AB_ArbreBinaire arbre, void* source, EC_FonctionCopierDansCollection copier, EC_FonctionLibererDeCollection liberer)
{
void* donnee =copier(source);
  liberer(arbre->lElement);
  arbre->lElement=donnee;
}


AB_ArbreBinaire AB_ajouterRacine(AB_ArbreBinaire fg, AB_ArbreBinaire fd, void* source,  EC_FonctionCopierDansCollection copier, EC_FonctionLibererDeCollection liberer)
{
  AB_ArbreBinaire arbre;
  arbre=AB_arbreBinaire();
  AB_fixerFilsGauche(arbre,fg);
  AB_fixerFilsGauche(arbre,fd);
  AB_fixerElement(arbre,source,copier,liberer);
  return(arbre);
}

void AB_supprimerArbre(AB_ArbreBinaire arbre, EC_FonctionLibererDeCollection liberer)

{
  if (!(AB_estVide(arbre)))
  {
    AB_supprimerArbre(AB_obtenirFilsDroit(arbre),liberer);
    AB_supprimerArbre(AB_obtenirFilsGauche(arbre),liberer);
    liberer(AB_obtenirElement(arbre));
    free(arbre);
  }
}
