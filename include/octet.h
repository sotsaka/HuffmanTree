#ifndef __OCTET__
#define __OCTET__

typedef enum {bitA0,bitA1} bit;

typedef unsigned char octet;

octet O_Creeroctet(bit,bit,bit,bit,bit,bit,bit,bit);

bit O_obtenirIemeBit(octet,int);

#endif
