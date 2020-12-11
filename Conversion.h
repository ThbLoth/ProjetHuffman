/*****************************************************************//**
 * \file   Conversion.h
 * \brief  Appel de la fonction Conversion.
 * 
 * \author Theophile BAPTISTE BOUGON theophile.baptiste.bougon@efrei.net
 * Thibault LOTH thibault.loth@efrei.net
 * Maxime GARNIER maxime.garnier@efrei.net
 * Maladele WATT maladele.watt@efrei.net
 * Alexandre Delfosse alexandre.delfosse@efrei.net
 * \date   December 2020
 *********************************************************************/
#ifndef CONVERSION
#define CONVERSION

/**
 * \brief Fonction permettant de convertir un texte en binaire.
 *		\n Exemple :
 *		 \code{.c}
 *		Conversion(fic);
 *		 \endcode
 *\param fic : fichier texte a traduire
 *\return Fichier texte traduit 
 */
void Conversion(FILE*);

#endif
