#ifndef __TDC__
#define __TDC__

#include "octet.h"
#include "codebinaire.h"

#define MAX 256

typedef CB_CodeBinaire* TDC_TableDeCodage; 

//créer un table de codage vide
TDC_TableDeCodage TDC_tableDeCodage();

// ajouter un élément 
void TDC_ajouter(TDC_TableDeCodage, octet,CB_CodeBinaire);

//vérifier si un octet est présente
int TDC_estPresent(TDC_TableDeCodage, octet);

//obtenir un code binaire depuis un octet
CB_CodeBinaire TDC_obtenirCode(TDC_TableDeCodage, octet);

//obtenir le nombre d'élements présents
int TDC_nbElements(TDC_TableDeCodage);

//libérerla table de codage et tous ses éléments
void TDC_supprimerTDC(TDC_TableDeCodage);



#endif
