#ifndef __DECOMPRESSION__
#define __DECOMPRESSION__

#include <stdio.h>
#include <stdlib.h>

#include "arbrehuffman.h"
#include "octet.h"
#include "statistiques.h"



octet LectureOctetCompresse (FILE*);

void EcritureOctetDecompresse (FILE*,octet);

void DecompressionDonne(FILE*,AH_ArbreHuffman,char[],int);


void lectureEnTete(char[],S_Statistiques*,int*,char[],FILE*);


void lectureIdentifiant(FILE*,char*);

int lectureTaille(FILE*);

S_Statistiques lectureStat(int,FILE*);

void decompression(char*);


#endif
