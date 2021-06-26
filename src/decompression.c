#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "decompression.h"
#include "arbrehuffman.h"
#include "octet.h"
#include "statistiques.h"
#include "creationArbre.h"



void DecompressionDonne(FILE * f,AH_ArbreHuffman a,char nom[],int taille) {

	FILE* fd = NULL;
	fd= fopen(nom,"w");
	octet o;

	CB_CodeBinaire cTotal = CB_codeBinaire();
	CB_CodeBinaire c=CB_codeBinaire();	
	while (!feof(f)) {

		fread(&o,sizeof(unsigned char),1,f);
		CB_supprimer(c);
		c = CB_codeBinaire();
		for (int i = 0;i<8;i++){
			bit b = O_obtenirIemeBit(o,i);
			CB_ajouterBitIemePosition(&c,b,i+1);
		}

		cTotal = CB_concatener(cTotal,c);		
	}
	
	int count = 1;
	int pos = 1;	
	while (count <= taille - 1){
		AH_ArbreHuffman temp = a;
		while (AH_estFeuille(temp) == 0){
			bit b = CB_obtenirBitIemePos(cTotal,pos);
			pos = pos +1;
			temp = AH_parcourirArbre(temp,b);
		}
		o = AH_obtenirOctet(temp);
		count++;
		fwrite(&o,sizeof(octet),1,fd);
	}

	fclose(f);
	fclose(fd);
	CB_supprimer(cTotal);
	CB_supprimer(c);

}


void lectureEnTete(char nomFichier[],S_Statistiques* pstat,int* ptaille,char* ext,FILE* f){
	
	lectureIdentifiant(f,ext);
	*ptaille=lectureTaille(f);
	*pstat=lectureStat(*ptaille,f);

}


void lectureIdentifiant(FILE* f,char* ext){

  int taille_identifiant=4;
  fread(ext,sizeof(char),taille_identifiant,f);
}


int lectureTaille(FILE* f){

	int result;
	fread(&result,sizeof(int),1,f);
	return result;
}


S_Statistiques lectureStat(int taille,FILE* f){

	S_Statistiques stat= S_statistiques();
	int c = 0;
	octet o;
	int nbOccurence;
	while (c<taille)  {
		fread(&o,sizeof(octet),1,f);
		fread(&nbOccurence,sizeof(int),1,f);
		S_ajouterStat(stat,o,nbOccurence);
		c=c+nbOccurence;
	}
	
	return stat;

}


void decompression(char nomFichier[]){
	FILE* fichierCompresse = NULL;
	fichierCompresse= fopen(nomFichier,"r");
	int taille;
	S_Statistiques stat;
	char* extension=(char*)malloc(4*sizeof(char));
	AH_ArbreHuffman arbre;

	lectureEnTete(nomFichier,&stat,&taille,extension,fichierCompresse);

	arbre = constructionArbre(stat);
	
	char nomFD[50];
	int t = strlen(nomFichier);
	
	for (int i=0;i<(t-4);i++){
		nomFD[i]=nomFichier[i];
	}
	
	for (int i=t-4;i<t;i++){
	  nomFD[i]=extension[i-t+4];
	}
	DecompressionDonne(fichierCompresse,arbre,nomFD,taille);
	free(extension);
	AH_supprimerArbre(arbre);
	S_supprimerStats(stat);
}
