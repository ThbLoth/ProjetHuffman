/*****************************************************************//**
 * \file   main.c
 * \brief  Fonction mere du programme
 * 
 * \author Maxime GARNIER maxime.garnier@efrei.net\n
 * Thibault LOTH thibault.loth@efrei.net\n
 * Theophile BAPTISTE BOUGON theophile.baptiste.bougon@efrei.net\n
 * Maladele WATT maladele.watt@efrei.net\n
 * Alexandre DELFOSSE alexandre.delfosse@efrei.net
 * \date   December 2020
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "CompressionHuffman.h"
#include "CompressionHuffman.c"

int main()
{
	/**
	 * \brief Permet d'enlever les fichiers crees par le logiciel durant une precedente execution
	 */
	remove("output.txt");
	remove("dico.txt");
	remove("traduction.txt");
	remove("binary.txt");

	/**
	 * \brief Permet d'executer toutes les fonctions pour encoder un fichier .txt, contenues dans CompressionHuffman.h
	 */
	encodage_huffman();
	return 0;
}

