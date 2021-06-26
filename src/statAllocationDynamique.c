#ifndef ___SAD___
#define ___SAD___

#include <string.h>
#include <stdlib.h>


#include "statistiques.h"
#include "statAllocationDynamique.h"

void* SAD_copierStat(void*  stat)
{
	statistique* resultat = (statistique*)malloc(sizeof(statistique));
	memcpy((void*)resultat,stat,sizeof(statistique));
	return (void*)resultat;
}

void SAD_desallouerStat(void* stat)
{
	free(stat);
}

#endif