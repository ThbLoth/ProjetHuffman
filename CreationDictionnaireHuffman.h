/*****************************************************************//**
 * \file   CreationDictionnaireHuffman.h
 * \brief  Appels des fonctions pour la creation du dictionnaire d'Huffman.
 * 
 * \author Maxime GARNIER maxime.garnier@efrei.net\n
 * Thibault LOTH thibault.loth@efrei.net\n
 * Theophile BAPTISTE BOUGON theophile.baptiste.bougon@efrei.net\n
 * Maladele WATT maladele.watt@efrei.net\n
 * Alexandre DELFOSSE alexandre.delfosse@efrei.net
 * \date   December 2020
 *********************************************************************/
#ifndef CREATIONDICTIONNAIREHUFFMAN
#define CREATIONDICTIONNAIREHUFFMAN

 /**
  * \brief Permet la creation d'une liste binaire
  *		\n Example :
  *		\code{.c}
  *		Creation_Dico(a->left, Creation_list_binaire(0, binaire))
  *		\endcode
  * \param nb Nombre binaire qu'il faut inserer dans une liste binaire deja existante
  * \param binaire Liste binaire deja existante
  * \return Liste binaire
  */
list_binaire* Creation_list_binaire(int, list_binaire*);

/**
 * \brief Permet la suppression du dernier nombre binaire dans une liste binaire
 *		\n Example :
 *		\code{.c}
 *		binaire = suppression_derniere_val(binaire)
 *		\endcode
 * \param binaire Liste binaire
 * \return Liste binaire sans son dernier nombre
 */
list_binaire* suppression_derniere_val(list_binaire*);

/**
 * \brief Permet la creation du dictionnaire d'Huffman
 *		\n Example :
 *		\code{.c}
 *		Creation_Dico(arbre_huff, binaire)
 *		\endcode
 * \param binaire Liste binaire
 * \return Dictionnaire d'Huffman
 */
void Creation_Dico(arbre, list_binaire*);

#endif
