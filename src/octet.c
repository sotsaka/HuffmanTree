#include <stdlib.h>
#include <stdio.h>

#include "octet.h"


octet O_Creeroctet(bit b1,bit b2,bit b3,bit b4,bit b5,bit b6,bit b7,bit b8)
{

  bit base2[8];
  base2[0]=b1;
  base2[1]=b2;
  base2[2]=b3;
  base2[3]=b4;
  base2[4]=b5;
  base2[5]=b6;
  base2[6]=b7;
  base2[7]=b8;
  octet result=0;

  if (base2[0]==bitA1)
  {
  	result=1;
  }




  for (int i = 1; i < 8; ++i)
  {
  	if (base2[i]==bitA1)
  	{	
  		int exp=2;
  		for(int j=1;j<i;j++)
		{
			exp=exp*2;
		}
  		result=result+exp;
  	}
  }
  return result;


}


bit O_obtenirIemeBit (octet o, int i)
{
	octet val = o;
	bit temp[8];

	for (int k = 0; k <8; ++k)
	{
		if (val%2==1)
		{
			temp[k]=bitA1;
		}
		else 
		{
			temp[k]=bitA0;	
		}
		val = val /2;

	}
	return temp[i];
}

