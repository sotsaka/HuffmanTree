#ifndef ___FDP___
#define ___FDP___

#include "arbrehuffman.h"
#include "listechainee.h"
#include "arbreAllocationDynamique.h"

typedef LC_ListeChainee FDP_FileDePriorite;

int FDP_nbOccurence(FDP_FileDePriorite); //////////
		
FDP_FileDePriorite FDP_fileDePriorite();

int FDP_estVide(FDP_FileDePriorite);

int FDP_nbElements(FDP_FileDePriorite);

void FDP_enfiler(FDP_FileDePriorite*, AH_ArbreHuffman);

void FDP_defiler(FDP_FileDePriorite*);

AH_ArbreHuffman FDP_obtenirArbre(FDP_FileDePriorite);


#endif




