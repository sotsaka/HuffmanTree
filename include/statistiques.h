#ifndef __S__
#define __S__

#include "octet.h"
#include "listechainee.h"

#define MAX 256

typedef struct statistique {
	octet o;
	int occurence;
} statistique;

typedef int* S_Statistiques;

typedef LC_ListeChainee ListeOctets;

void desallouerOctet(void*);

S_Statistiques S_statistiques();

void S_ajouterStat(S_Statistiques,octet,int);

int S_estPresentOctet(S_Statistiques,octet);

int S_obtenirOccurence(S_Statistiques, octet);

int S_nbElements(S_Statistiques);

ListeOctets S_obtenirOctetsPresents(S_Statistiques);

statistique S_obtenirStat(S_Statistiques, octet);

void S_supprimerStats(S_Statistiques);



#endif
