#include "arbrehuffman.h"
#include <stdlib.h>
#include <string.h>

void* AAD_copierArbre(void* arbre)
{
  AH_ArbreHuffman* resultat = (AH_ArbreHuffman*)malloc(sizeof(AH_ArbreHuffman));
  memcpy((void*)resultat,arbre,sizeof(AH_ArbreHuffman));
  return (void*)resultat;
}

void AAD_desallouerArbre(void* arbre)
{
  free(arbre);
}
