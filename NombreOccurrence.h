/*****************************************************************//**
 * \file   NombreOccurrence.h
 * \brief  Appel des fonctions creation_liste_occ et nb_Occurences. 
 * 
 * \author Theophile BAPTISTE BOUGON theophile.baptiste.bougon@efrei.net
 * Thibault LOTH thibault.loth@efrei.net
 * Maxime GARNIER maxime.garnier@efrei.net
 * Maladele WATT maladele.watt@efrei.net
 * Alexandre Delfosse alexandre.delfosse@efrei.net
 * \date   December 2020
 *********************************************************************/
#ifndef NOMBREOCCURENCE
#define NOMBREOCCURENCE

/**
 * \brief Fonction de creation d'une liste chainee
 *		\n Exemple : 
 *		 \code{.c}
 *		*stock_occ = creation_liste_occ(i, tab[i]);
 *		 \endcode
 * \param Code ascii correspondant a une lettre/ un caractere
 * \param Nombre d'occurences d'une lettre
 * \return Un nouveau maillon
 */
list creation_liste_occ(int, int);

/**
 * \brief Fonction permettant le comptage d'occurences d'une lettre / caractere.
 *		\n Exemple : 
 *		 \code{.c}
 *		nb_Occurrences(&liste_occurence);
 *		 \endcode
 * \param Liste appellee par adresse
 * \return La liste chainee avec le nombre d'occurences exact de chaque caractere
 */
void nb_Occurrences(list*);

#endif