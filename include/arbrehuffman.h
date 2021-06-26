/*!
 * \file abreHuffman.h
 * \brief Implantation du TAD ArbreHuffman
 * \author Groupe 2.3
 * \version 1.0
 */
#ifndef ___AH___
#define ___AH___



#include "arbrebinaire.h"
#include "octet.h"
#include "codebinaire.h"
#include "statistiques.h"

/*!
 * \typedef AB_ArbreBinaire AH_ArbreHuffman
 * \brief AH_ArbreHuffman est un AB_ArbreBinaire dont l'élément contenu est de type statistique 
 */
typedef AB_ArbreBinaire AH_ArbreHuffman;

/*!
 * \fn AH_ArbreHuffman AH_feuilleDeHuffman(statistique* stat)
 * \brief Création d'une feuille de Huffman contenant un élément de type statistique
 * \param stat Statistique de la feuille
 * \return AH_ArbreHuffman
 */						
AH_ArbreHuffman AH_feuilleDeHuffman(statistique* stat);


/*!
 * \fn AH_ArbreHuffman AH_insererElement(AH_ArbreHuffman a1, AH_ArbreHuffman a2)
 * \brief Crée la racine de deux arbres de Huffman. La pondération de la racine est la somme des pondérations des deux sous arbres
 * \param a1 Arbre 1
 * \param a2 Arbre 2
 * \return AH_ArbreHuffman 
 */
AH_ArbreHuffman AH_insererElement(AH_ArbreHuffman a1, AH_ArbreHuffman a2);


/*!
 * \fn CB_CodeBinaire AH_obtenirCodeBinaire(AH_ArbreHuffman a, octet o)
 * \brief Donne le code binaire correspondant à un octet. On part de la racine avec la plus grande pondération et on descend jusqu'aux feuilles de Huffman
 * \param a Arbre de Huffman que l'on va parcourir
 * \param o Octet dont on veut obtenir le code binaire
 * \return CB_CodeBinaire
 */
CB_CodeBinaire AH_obtenirCodeBinaire(AH_ArbreHuffman a, octet o);


/*!
 * \fn int AH_estFeuille(AH_ArbreHuffman arbre)
 * \brief Permet de savoir si un noeud possède des fils ou non (si non alors c'est une feuille)
 * \param a Arbre de Huffman dont l'on veut savoir si c'est une feuille ou non
 * \return int
 */
int AH_estFeuille(AH_ArbreHuffman arbre);


/*!
 * \fn octet AH_obtenirOctet(AH_ArbreHuffman arbre)
 * \brief Donne l'octet d'un noeud donné. Le noeud doit contenir un octet c'est à dire être une feuille
 * \param arbre Arbre dont on veut connaître l'octet
 * \return octet
 */
octet AH_obtenirOctet(AH_ArbreHuffman arbre);


/*!
 * \fn statistique AH_obtenirStat(AH_ArbreHuffman arbre)
 * \brief Donne la statistique contenu dans un arbre
 * \param arbre Arbre dont on veut connâitre la statistique
 * \return statistique
 */  
statistique AH_obtenirStat(AH_ArbreHuffman arbre);


/*!
 * \fn AH_ArbreHuffman AH_parcourirArbre(AH_ArbreHuffman arbre, bit b)
 * \brief Permet d'avoir accès au sous arbre gauche si le bit vaux 0 et au sous abre droit si il vaut 1
 * \param arbre Arbre de Huffman que l'on parcourt
 * \param b Bit que l'on entre en fonction de la direction de parcours souhaitée
 * \return AH_ArbreHuffman
 */
AH_ArbreHuffman AH_parcourirArbre(AH_ArbreHuffman arbre, bit b);


/*!
 * \fn void AH_supprimerArbre(AH_ArbreHuffman arbre)
 * \brief Permet de supprimer l'arbre de Huffman
 * \param arbre Arbre que l'on veut supprimer
 * \return void
 */  
void AH_supprimerArbre(AH_ArbreHuffman arbre);

#endif

