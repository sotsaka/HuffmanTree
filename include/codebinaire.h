#ifndef ___CB___
#define ___CB___

#include "listechainee.h"
#include "octet.h"

typedef LC_ListeChainee CB_CodeBinaire;



CB_CodeBinaire CB_codeBinaire();
int CB_tailleCodeBinaire(CB_CodeBinaire);
void CB_ajouterBitIemePosition(CB_CodeBinaire*,bit,int);
bit CB_obtenirBitIemePos(CB_CodeBinaire,int);
CB_CodeBinaire CB_concatener(CB_CodeBinaire, CB_CodeBinaire);
void CB_supprimer(CB_CodeBinaire);
#endif
