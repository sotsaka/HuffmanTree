#include "arbrehuffman.h"
#include "statAllocationDynamique.h"
#include <stdio.h>

AH_ArbreHuffman AH_feuilleDeHuffman(statistique* stat)
{
  AH_ArbreHuffman arbre;
  
  arbre=AB_arbreBinaire();
  AB_fixerElement(arbre,stat,SAD_copierStat,SAD_desallouerStat);
  return(arbre);
}


AH_ArbreHuffman AH_insererElement(AH_ArbreHuffman a1, AH_ArbreHuffman a2)
{
  AH_ArbreHuffman racine;
  statistique stat;
 
  stat.occurence =  AH_obtenirStat(a1).occurence + AH_obtenirStat(a2).occurence;
  racine = AH_feuilleDeHuffman(&stat);
		      
  if(AH_obtenirStat(a2).occurence<AH_obtenirStat(a1).occurence)
    {
      AB_fixerFilsGauche(racine,a2);
      AB_fixerFilsDroit(racine,a1);
    }
  else
    {
      AB_fixerFilsGauche(racine,a1);
      AB_fixerFilsDroit(racine,a2);
    }
  return(racine);
}
     

      
  
CB_CodeBinaire AH_obtenirCodeBinaire(AH_ArbreHuffman a, octet o)
{
  CB_CodeBinaire res0,res1,cb;
  bit b0 = bitA0;
  bit b1 = bitA1;
  
  if (AH_estFeuille(AH_parcourirArbre(a,b0)) && (AH_obtenirOctet(AH_parcourirArbre(a,b0)) == o))
  {
	cb = CB_codeBinaire();
	CB_ajouterBitIemePosition(&cb,b0,1);
	return cb;
  }
  else 
  {
	if (AH_estFeuille(AH_parcourirArbre(a,b1)) && (AH_obtenirOctet(AH_parcourirArbre(a,b1)) == o)){
		cb = CB_codeBinaire();
		CB_ajouterBitIemePosition(&cb,b1,1);
		return cb;
	}
	else 
	{
		res0 = CB_codeBinaire();
		res1 = CB_codeBinaire();
		if (AH_estFeuille(AH_parcourirArbre(a,b0)) == 0)
			res0 = AH_obtenirCodeBinaire(AH_parcourirArbre(a,b0),o);
		if (AH_estFeuille(AH_parcourirArbre(a,b1)) == 0)
			res1 = AH_obtenirCodeBinaire(AH_parcourirArbre(a,b1),o);
		
		if (CB_tailleCodeBinaire(res0) != 0)
		{
			CB_ajouterBitIemePosition(&res0,b0,1);
			return res0;
		}
		else 
		{
			if (CB_tailleCodeBinaire(res1) != 0)
			{
				CB_ajouterBitIemePosition(&res1,b1,1);
				return res1;
			}
			else 
			{
				return CB_codeBinaire();	
			}
		}
	
		
	}  
   }
  
  
}


int AH_estFeuille(AH_ArbreHuffman arbre)
{
  return (AB_estVide(AB_obtenirFilsGauche(arbre)) && AB_estVide(AB_obtenirFilsDroit(arbre)));
}


octet AH_obtenirOctet(AH_ArbreHuffman arbre)
{
  return AH_obtenirStat(arbre).o;
}


AH_ArbreHuffman AH_parcourirArbre(AH_ArbreHuffman arbre, bit b)
{
  if (b==bitA1)
    {
      return(AB_obtenirFilsDroit(arbre));
    }
  else
    {
      return(AB_obtenirFilsGauche(arbre));
    }
}

statistique AH_obtenirStat(AH_ArbreHuffman arbre)
{
  return *((statistique*)AB_obtenirElement(arbre));
}
	 
	   
void AH_supprimerArbre(AH_ArbreHuffman arbre)
{
  AB_supprimerArbre(arbre, SAD_desallouerStat);
}
