#include "codebinaire.h"
#include "bitAllocationDynamique.h"
#include "listechainee.h"


CB_CodeBinaire CB_codeBinaire()
{
  return LC_listeChainee();
}


  
int CB_tailleCodeBinaire(CB_CodeBinaire code)
{
  if (LC_estVide(code)) {
    return 0;
  }
  else {
    return (CB_tailleCodeBinaire(LC_obtenirListeSuivante(code))+1);
  }
		
}
  
void CB_ajouterBitIemePosition(CB_CodeBinaire* pcode,bit b,int i)
{
  if (i==1) {
    LC_ajouter(pcode,&b,BAD_copierBit);
  }
  else {
    CB_CodeBinaire temp= LC_obtenirListeSuivante(*pcode);
    CB_ajouterBitIemePosition(&temp,b,i-1);
    LC_fixerListeSuivante(pcode,temp);
  }
}
bit CB_obtenirBitIemePos(CB_CodeBinaire code,int i)
{
  if (i==1){
    return *((bit*)LC_obtenirElement(code));
  }
  else {
    return CB_obtenirBitIemePos(LC_obtenirListeSuivante(code),i-1);
  }
}



CB_CodeBinaire CB_concatener(CB_CodeBinaire c1, CB_CodeBinaire c2){
	CB_CodeBinaire res =CB_codeBinaire();

	int taille1 = CB_tailleCodeBinaire(c1);
	int taille2 = CB_tailleCodeBinaire(c2);
	int i;



	res=LC_copier(c1,BAD_copierBit);
  
	CB_CodeBinaire temp = c2;
	for (i=1;i<=taille2;i++){
		bit b = *((bit*)LC_obtenirElement(temp));
		CB_ajouterBitIemePosition(&res,b,taille1 + i);
    	temp=LC_obtenirListeSuivante(temp);
	}


	
	return res;

}

void CB_supprimer(CB_CodeBinaire c)
{
	LC_supprimer(&c,BAD_desallouerBit);
}


