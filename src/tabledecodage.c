#include <stdlib.h>
#include "octet.h"
#include "codebinaire.h"
#include "tabledecodage.h"
#include <assert.h>


TDC_TableDeCodage TDC_tableDeCodage()
{
	int i;
	TDC_TableDeCodage t;
	
	t=(CB_CodeBinaire*)malloc(MAX*sizeof(CB_CodeBinaire));
	
	for (i=0;i<MAX;i++)
		t[i]=NULL;	
		
	return t;	
}

void TDC_ajouter(TDC_TableDeCodage t, octet o,CB_CodeBinaire c)
{
	CB_CodeBinaire code;
	code = c;	
	t[o]=code;
}

int TDC_estPresent(TDC_TableDeCodage t , octet o)
{
	if (t[o] == NULL)
	{ 
		return 0; //faux
	}
	else
	{
		return 1; //vrai
	}
}

CB_CodeBinaire TDC_obtenirCode(TDC_TableDeCodage t, octet o)
{
	assert(TDC_estPresent(t,o) == 1);
	CB_CodeBinaire code;
	code=t[o];
	
	return code;
}

int TDC_nbElements(TDC_TableDeCodage t)
{
	int i;
	int res = 0;
	
	for (i=0;i<MAX;i++)
	{
		if (t[i] != NULL)
		{
			res++;
		}
	}
	return res;
}

void TDC_supprimerTDC(TDC_TableDeCodage t)
{
	free(t);
}



