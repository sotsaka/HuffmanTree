#include "compression.h"
#include "decompression.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){

	if (*argv[1] == 'c') {
		char* nomFichier = argv[2];
		compression(nomFichier);
	}
	else {
		if (*argv[1] == 'd'){
			char* nomFichier = argv[2];

			int t = strlen(nomFichier);
			char* extHuff=(char*)malloc(5*sizeof(char));;
			char extHuffAttendu[5]="huff";
			int j=0;
			for(int i=t-4; i<t+1; i++){
				extHuff[j] = nomFichier[i];
				j++;
			}
			if(strcmp(extHuff,extHuffAttendu)==0){// Si chaînes identiques
					decompression(nomFichier);
			}else{
				printf("erreur : ce fichier n'est pas un fichier .huff \n");
			}

		}
		else {
			printf("option invalide\n");
		}
	}

	return 0;

}
