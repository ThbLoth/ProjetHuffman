/*****************************************************************//**
 * \file   CreationArbreHuffman.h
 * \brief  Appels des fonctions pour la creation de l'arbre d'Huffman d'un fichier .txt donne.
 * 
 * \author Maxime GARNIER maxime.garnier@efrei.net\n
 * Thibault LOTH thibault.loth@efrei.net\n
 * Theophile BAPTISTE BOUGON theophile.baptiste.bougon@efrei.net\n
 * Maladele WATT maladele.watt@efrei.net\n
 * Alexandre DELFOSSE alexandre.delfosse@efrei.net
 * \date   December 2020
 *********************************************************************/
#ifndef CREATIONARBREHUFFMAN
#define CREATIONARBREHUFFMAN

 /**
  * \brief Permet de creer un noeud dans l'arbre.
  *		\n Example :
  *		\code{.c}
  *		nouvel_element->data = creation_noeud(lettre, occ)
  *		\endcode
  * \param lettre Lettre dans le maillon donne.
  * \param occ Nombre d'occurrence de la lettre donnee par le maillon.
  * \return Nouveau noeud
  */
arbre creation_noeud(int, int);

/**
 * \brief Permet de creer un element dans un arbre.
 *		\n Example :
 *		\code{.c}
 *		temp->next = creation_elem_noeud(liste_occ->lettre, liste_occ->nb_occ)
 *		\endcode
 * \param lettre Lettre dans le maillon donne.
 * \param occ Nombre d'occurrence de la lettre donnee par le maillon.
 * \return Nouvel element de l'arbre
 */
tree_array* creation_elem_noeud(int, int);

/**
 * \brief Permet la creation d'une liste de noeuds
 *		\n Example :
 *		\code{.c}
 *		liste_transformee = creation_liste_arbre(liste_occurence)
 *		\endcode
 * \param liste_occ La liste de toutes les occurences de lettres
 * \return Liste de noeuds pour construire l'arbre d'Huffman
 */
tree_array* creation_liste_arbre(node*);

/**
 * \brief Fonction permettant la creation de l'arbre d'Huffman.
 *		\n Example :
 *		\code{.c}
 *		arbre_huff = arbre_huffman(liste_transformee)
 *		\endcode
 * \param liste La liste de noeuds creee a la fonction creation_liste_arbre()
 * \return Arbre d'Huffman
 */
arbre arbre_huffman(tree_array*);

#endif
