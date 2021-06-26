#include <string.h>
#include <stdlib.h>


#include "octet.h"
#include "bitAllocationDynamique.h"

void* BAD_copierBit(void*  b)
{
  bit* resultat = (bit*)malloc(sizeof(bit));
  memcpy((void*)resultat,b,sizeof(bit));
  return (void*)resultat;
}

void BAD_desallouerBit(void* b){
  free(b);
}
