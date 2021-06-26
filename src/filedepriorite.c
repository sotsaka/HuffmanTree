#include <assert.h>
#include "filedepriorite.h"
#include "arbrehuffman.h"


FDP_FileDePriorite FDP_fileDePriorite(){
	
	return LC_listeChainee();
}

int FDP_nbElements(FDP_FileDePriorite f){
	
	if (LC_estVide(f)) {
    return 0;
  }
  else {
    return (FDP_nbElements(LC_obtenirListeSuivante(f))+1);
  }
}


int FDP_estVide(FDP_FileDePriorite f){
	
	return LC_estVide(f);
}


int FDP_nbOccurence(FDP_FileDePriorite f){
	
	AH_ArbreHuffman* parbre = LC_obtenirElement(f);
	statistique stat = AH_obtenirStat(*parbre);
	return stat.occurence;
}


void FDP_enfiler(FDP_FileDePriorite* f, AH_ArbreHuffman a){
	LC_ListeChainee temp;
	
	if (FDP_estVide(*f) == 1){
		LC_ajouter(f,&a,AAD_copierArbre);
	} 
	else{
		if (FDP_nbOccurence(*f) > AH_obtenirStat(a).occurence){
			LC_ajouter(f,&a,AAD_copierArbre);
		}
		else{
			temp = LC_obtenirListeSuivante(*f);
			FDP_enfiler(&temp,a);
			LC_fixerListeSuivante(f,temp);
		}
	}	
}


void FDP_defiler(FDP_FileDePriorite* f){
	assert(FDP_estVide(*f) == 0);
	
	LC_supprimerTete(f,AAD_desallouerArbre);
}


AH_ArbreHuffman FDP_obtenirArbre(FDP_FileDePriorite f){
	assert(FDP_estVide(f) == 0);
	AH_ArbreHuffman* parbre = LC_obtenirElement(f);
	return *parbre;
	
}

