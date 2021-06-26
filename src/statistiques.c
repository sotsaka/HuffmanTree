#include <stdlib.h>
#include "octet.h"
#include "statistiques.h"
#include "listechainee.h"
#include <assert.h>
#include <string.h>


void* copierOctet(void*  o)
{
	octet* resultat = (octet*)malloc(sizeof(octet));
	memcpy((void*)resultat,o,sizeof(octet));
	return (void*)resultat;
}

void desallouerOctet(void* o)
{
	free(o);
}


S_Statistiques S_statistiques()
{
	S_Statistiques s;
	int i;
	
	s=(int*)malloc(MAX*sizeof(int));
	
	for (i=0;i<MAX;i++)
		s[i]=0;	
		
	return s;		
}


void S_ajouterStat(S_Statistiques s,octet o,int occ)
{
	s[o] = occ;
}

int S_estPresentOctet(S_Statistiques s,octet o)
{
	if (s[o] == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int S_obtenirOccurence(S_Statistiques s, octet o)
{
	assert(S_estPresentOctet(s,o) == 1);
	return s[o];
}

int S_nbElements(S_Statistiques s)
{
	int i;
	int res = 0;
	
	for (i=0;i<MAX;i++)
	{
		if (s[i] != 0)
		{
			res++;
		}
	}
	return res;
}

ListeOctets S_obtenirOctetsPresents(S_Statistiques s)
{
	ListeOctets liste;
	int i;

	liste = LC_listeChainee();
	
	for (i=0;i<MAX;i++)
	{
		if (s[i] != 0)
		{	
			LC_ajouter(&liste,&i,copierOctet);
		}
	}
	return liste;
}

statistique S_obtenirStat(S_Statistiques s, octet o)
{
	statistique stat;
	
	stat.o = o;
	stat.occurence = s[o];
	
	return stat;
}



void S_supprimerStats(S_Statistiques s)
{
	free(s);
}
