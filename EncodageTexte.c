/*****************************************************************//**
 * \file   EncodageTexte.c
 * \brief  Fichier source comprenant les fonctions permettant d'encoder le fichier .txt.
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
#include "EncodageTexte.h"

void encodage(void)
{
    FILE* fic; 
    fopen_s(&fic,"Alice.txt", "r");

    FILE* fdic;  
    fopen_s(&fdic,"dico.txt","r");

    FILE* fout; 
    fopen_s(&fout,"traduction.txt","a");

    char lettre;
    if (fic == NULL || fdic == NULL || fout == NULL)
    {
        printf("Erreur mémoire");
        exit(1);
    }

    while ((lettre = fgetc(fic)) != EOF)
    {
        fseek(fdic, 0, SEEK_SET);
        while (fgetc(fdic) != lettre)
        {
            while (fgetc(fdic) != '\n')
            {
                lettre = lettre;
            }
        }

        fgetc(fdic);

        while ((lettre = fgetc(fdic)) != '\n')
        {
            fprintf(fout, "%c", lettre);
        }
    }
    fclose(fout);
    fclose(fdic);
    fclose(fic);
}