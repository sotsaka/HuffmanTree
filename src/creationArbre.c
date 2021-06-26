#include "creationArbre.h"
#include "statAllocationDynamique.h"

FDP_FileDePriorite constructionFileDePriorite(S_Statistiques s){  
	ListeOctets liste;
	statistique stat;
	octet* po;
	FDP_FileDePriorite f;
	AH_ArbreHuffman a;
	
	f = FDP_fileDePriorite();
	
	liste = S_obtenirOctetsPresents(s);
	while (LC_estVide(liste) == 0){
		po = LC_obtenirElement(liste);
		stat = S_obtenirStat(s,*po);
		statistique* pstat = SAD_copierStat(&stat);  //utile? 
		a = AH_feuilleDeHuffman(pstat);
		FDP_enfiler(&f,a);
		liste = LC_obtenirListeSuivante(liste);  //remplacer par supprimer tete	
	}
	return f;
	
}


AH_ArbreHuffman constructionArbre(S_Statistiques s){
	AH_ArbreHuffman arbre, a1, a2;
	FDP_FileDePriorite f;
		
	f = constructionFileDePriorite(s);
	
	while (FDP_nbElements(f) > 1){
		a1 = FDP_obtenirArbre(f);
		FDP_defiler(&f);
		a2 = FDP_obtenirArbre(f);
		FDP_defiler(&f);
		arbre = AH_insererElement(a1,a2); 
		FDP_enfiler(&f,arbre);
	}
	
	return FDP_obtenirArbre(f);
}
