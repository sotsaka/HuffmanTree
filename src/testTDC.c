#include <CUnit/Basic.h>
#include <stdlib.h>
#include "octet.h"
#include "codebinaire.h"
#include "tabledecodage.h"

int init_suite_success(void)
{
  return 0;
}

int clean_suite_success(void)
{
  return 0;
}

void testEcraserAjout()
{
	TDC_TableDeCodage resultatAttendu;
	TDC_TableDeCodage resultatObtenu;
	bit b0 = bitA0;
	bit b1 = bitA1;
	octet o1 = 1;
	CB_CodeBinaire c1 = CB_codeBinaire();
	CB_CodeBinaire c2 = CB_codeBinaire();
	
	CB_ajouterBitIemePosition(&c1, b0, 1);
	CB_ajouterBitIemePosition(&c1, b0, 1);
	CB_ajouterBitIemePosition(&c1, b1, 1);
	
	CB_ajouterBitIemePosition(&c2, b1, 1);
	CB_ajouterBitIemePosition(&c2, b1, 1);
	CB_ajouterBitIemePosition(&c2, b0, 1);
	
	resultatAttendu = TDC_tableDeCodage();
	TDC_ajouter(resultatAttendu,o1,c2);
	
	resultatObtenu = TDC_tableDeCodage();
	TDC_ajouter(resultatObtenu,o1,c1);
	TDC_ajouter(resultatObtenu,o1,c2);

	CU_ASSERT_EQUAL(*resultatObtenu,*resultatAttendu);
  
	TDC_supprimerTDC(resultatAttendu);
	TDC_supprimerTDC(resultatObtenu);
}

void testObtenirCode()
{
	CB_CodeBinaire resultatAttendu;
	CB_CodeBinaire resultatObtenu;
	TDC_TableDeCodage t;
	bit b0 = bitA0;
	bit b1 = bitA1;
	octet o1 = 1;
	octet o255 = 255;
	CB_CodeBinaire c1 = CB_codeBinaire();
	CB_CodeBinaire c2 = CB_codeBinaire();
	
	
	CB_ajouterBitIemePosition(&c1, b0, 1);
	CB_ajouterBitIemePosition(&c1, b0, 1);
	CB_ajouterBitIemePosition(&c1, b1, 1);
	
	CB_ajouterBitIemePosition(&c2, b1, 1);
	CB_ajouterBitIemePosition(&c2, b0, 1);
	CB_ajouterBitIemePosition(&c2, b1, 1);
		
	resultatAttendu = c1;
	
	t = TDC_tableDeCodage();
	TDC_ajouter(t,o1,c1);
	TDC_ajouter(t,o255,c2);
	
	resultatObtenu = TDC_obtenirCode(t,o1);

	CU_ASSERT_EQUAL(resultatObtenu,resultatAttendu);
  
	TDC_supprimerTDC(t);
}

void testEstPresent()
{
	int resultatAttendu;
	int resultatObtenu;
	TDC_TableDeCodage t;
	bit b0 = bitA0;
	bit b1 = bitA1;
	octet o1 = 1;
	CB_CodeBinaire c = CB_codeBinaire();
	
	CB_ajouterBitIemePosition(&c, b0, 1);
	CB_ajouterBitIemePosition(&c, b0, 1);
	CB_ajouterBitIemePosition(&c, b1, 1);
		
	resultatAttendu = 1;
	
	t = TDC_tableDeCodage();
	TDC_ajouter(t,o1,c);
	
	resultatObtenu = TDC_estPresent(t,o1);

	CU_ASSERT_EQUAL(resultatObtenu,resultatAttendu);
  
	TDC_supprimerTDC(t);
}

void testNonEstPresent()
{
	int resultatAttendu;
	int resultatObtenu;
	TDC_TableDeCodage t;
	bit b0 = bitA0;
	bit b1 = bitA1;
	octet o1 =1;
	octet o2 =2;
	CB_CodeBinaire c = CB_codeBinaire();
	
	CB_ajouterBitIemePosition(&c, b0, 1);
	CB_ajouterBitIemePosition(&c, b0, 1);
	CB_ajouterBitIemePosition(&c, b1, 1);
		
	resultatAttendu = 0;
	
	t = TDC_tableDeCodage();
	TDC_ajouter(t,o1,c);
	
	resultatObtenu = TDC_estPresent(t,o2);

	CU_ASSERT_EQUAL(resultatObtenu,resultatAttendu);
  
	TDC_supprimerTDC(t);
}

void testNbElementsVide()
{
	int resultatAttendu;
	int resultatObtenu;
	TDC_TableDeCodage t;
		
	resultatAttendu = 0;
	
	t = TDC_tableDeCodage();

	resultatObtenu = TDC_nbElements(t);

	CU_ASSERT_EQUAL(resultatObtenu,resultatAttendu);
  
	TDC_supprimerTDC(t);
}

void testNbElements()
{
	int resultatAttendu;
	int resultatObtenu;
	octet o255 =255;
	octet o1 =1;
	octet o2 =2;
	bit b0 = bitA0;
	bit b1 = bitA1;
	TDC_TableDeCodage t= TDC_tableDeCodage();
	CB_CodeBinaire c = CB_codeBinaire();
		
	resultatAttendu = 3;
	
	CB_ajouterBitIemePosition(&c, b0, 1);
	CB_ajouterBitIemePosition(&c, b0, 1);
	CB_ajouterBitIemePosition(&c, b1, 1);
	
	TDC_ajouter(t,o1,c);
	
	c = CB_codeBinaire();
	
	CB_ajouterBitIemePosition(&c, b0, 1);
	CB_ajouterBitIemePosition(&c, b1, 1);
	CB_ajouterBitIemePosition(&c, b1, 1);
	
	TDC_ajouter(t,o2,c);
	
	c = CB_codeBinaire();
	
	CB_ajouterBitIemePosition(&c, b1, 1);
	CB_ajouterBitIemePosition(&c, b1, 1);
	CB_ajouterBitIemePosition(&c, b1, 1);
	
	TDC_ajouter(t,o255,c);
	
	resultatObtenu = TDC_nbElements(t);

	CU_ASSERT_EQUAL(resultatObtenu,resultatAttendu);
  
	TDC_supprimerTDC(t);
}


int main(int argc, char** argv)
{
  CU_pSuite pSuite = NULL;

  /*initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /*ajout d'une suite de tests*/
  pSuite=CU_add_suite("Tests des axiomes de TableDeCodage", init_suite_success, clean_suite_success);
  if (NULL == pSuite)
  {
    CU_cleanup_registry();
    return CU_get_error();
  }


  /*ajout des tests */

  if ((NULL == CU_add_test(pSuite, "ajouter : écraser lors d'un ajout", testEcraserAjout))
      || (NULL == CU_add_test(pSuite, "obtenirCode", testObtenirCode))
      || (NULL == CU_add_test(pSuite, "estPresent : sur un élement présent", testEstPresent))
      || (NULL == CU_add_test(pSuite, "estPresent : sur un élement non présent", testNonEstPresent))
      || (NULL == CU_add_test(pSuite, "nbElements : sur une table vide", testNbElementsVide))
      || (NULL == CU_add_test(pSuite, "nbElements : sur une table non vide", testNbElements))
    
      ) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*lancement des tests*/
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list ());
  printf("\n\n");

  /*Nettoyage du registre*/
  CU_cleanup_registry();
  return CU_get_error();
  
}
