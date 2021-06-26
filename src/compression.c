#include "octet.h"
#include "statistiques.h"
#include "tabledecodage.h"
#include "arbrehuffman.h"
#include "filedepriorite.h"
#include "creationArbre.h"
#include "listechainee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


S_Statistiques calculerStats(FILE* f){
	S_Statistiques s;
	octet o;
	int nb;
	
	s = S_statistiques();

	while (feof(f) == 0){
		fread(&o,sizeof(unsigned char),1,f);
		if (S_estPresentOctet(s,o) == 0){
			S_ajouterStat(s,o,1);
		}
		else{
			nb = S_obtenirOccurence(s,o);
			S_ajouterStat(s,o,nb+1);
		}
	}
	
	return s;
	
}

S_Statistiques creationStatistiques(char nomFichier[]){
	S_Statistiques s;
	FILE* f = NULL;
	
	f= fopen(nomFichier,"r");
	
	s = calculerStats(f);
	
	fclose(f);
	
	return s;
}

TDC_TableDeCodage arbreEnTableDeCodage(S_Statistiques s){
	AH_ArbreHuffman arbre;
	TDC_TableDeCodage t;
	CB_CodeBinaire c;
	octet* po;
	ListeOctets liste;
	
	
	arbre = constructionArbre(s);
	t = TDC_tableDeCodage();
	
	liste = S_obtenirOctetsPresents(s);
	
	while (LC_estVide(liste) == 0){
		po = LC_obtenirElement(liste);
		c = AH_obtenirCodeBinaire(arbre, *po); 
		TDC_ajouter(t,*po,c);
		LC_supprimerTete(&liste,desallouerOctet);
	}
	AH_supprimerArbre(arbre);
	return t;
}

int calculerLongueurFichier(S_Statistiques s){
	ListeOctets liste;
	octet* po;
	int res;
	
	liste = S_obtenirOctetsPresents(s);
	res = 0;
	
	while (LC_estVide(liste) == 0){
		po = LC_obtenirElement(liste);
		res = res +S_obtenirOccurence(s,*po);
		liste = LC_obtenirListeSuivante(liste);
	}
	
	return res;
	
}

void creationEnTete(FILE* f, char nomFichier[], S_Statistiques s){
	
	int taille = strlen(nomFichier);
	
	//identifiant
	char identifiant[4];
	

	identifiant[0] = nomFichier[taille-3];
	identifiant[1] = nomFichier[taille-2];
	identifiant[2] = nomFichier[taille-1];
	identifiant[3] = '\0';
	
	fwrite(&identifiant,sizeof(identifiant),1,f);
	
	//longueur
	int longueur = calculerLongueurFichier(s);
	
	fwrite(&longueur,sizeof(int),1,f);
	
	//statistiques (on écrit que ceux présents)
	
	ListeOctets liste = S_obtenirOctetsPresents(s);
	
	while (LC_estVide(liste) == 0){
		octet* po = LC_obtenirElement(liste);
		int occ = S_obtenirOccurence(s,*po);
		fwrite(po,sizeof(octet),1,f);
		fwrite(&occ,sizeof(int),1,f);
		liste = LC_obtenirListeSuivante(liste);
	}
	
}


void ecritureFichierHuffman(char nomFichier[], FILE* fichierCompresse, S_Statistiques s, TDC_TableDeCodage t){
	FILE* fichierBase = NULL;
	octet o;
	CB_CodeBinaire c=CB_codeBinaire();
	CB_CodeBinaire cTotal = CB_codeBinaire();
	bit b[8];
	
	fichierBase= fopen(nomFichier,"r");
	
	while (feof(fichierBase) == 0){
		fread(&o,sizeof(unsigned char),1,fichierBase);
		c = TDC_obtenirCode(t,o);
		cTotal = CB_concatener(cTotal,c);
	}
	
	while (CB_tailleCodeBinaire(cTotal) != 0){
		for (int i=0;i<8;i++){
			if (CB_tailleCodeBinaire(cTotal) == 0){
				b[i] = bitA0;
			}
			else {
				b[i] = CB_obtenirBitIemePos(cTotal,1);
				cTotal = LC_obtenirListeSuivante(cTotal);
			}
		}
		o = O_Creeroctet(b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]);
		fwrite(&o,sizeof(octet),1,fichierCompresse);
	}
	
	fclose(fichierBase);
	CB_supprimer(c);
	CB_supprimer(cTotal);
	
}

	


void compressionFichier(char nomFichier[], S_Statistiques s, TDC_TableDeCodage t){
	FILE* fichierCompresse = NULL;
	
	int taille = strlen(nomFichier);
	
	//creation du fichier
	char nomFichierCompresse[50]; 
	
	for (int i=0;i<(taille-3);i++){
		nomFichierCompresse[i]=nomFichier[i];
	}
	nomFichierCompresse[taille-3] = 'h';
	nomFichierCompresse[taille-2] = 'u';
	nomFichierCompresse[taille-1] = 'f';
	nomFichierCompresse[taille] = 'f';
	nomFichierCompresse[taille+1] = '\0';
	
	fichierCompresse= fopen(nomFichierCompresse,"w+");
	
	creationEnTete(fichierCompresse,nomFichier,s);
	
	ecritureFichierHuffman(nomFichier,fichierCompresse,s,t);
	
	fclose(fichierCompresse);
	
}


void compression(char nomFichier[]){
	S_Statistiques s;
	TDC_TableDeCodage t;
	
	s = creationStatistiques(nomFichier);
	
	t = arbreEnTableDeCodage(s);
	
	compressionFichier(nomFichier,s,t);
	
	TDC_supprimerTDC(t);
	
	S_supprimerStats(s);
	
}
